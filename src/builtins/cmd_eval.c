/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:03:42 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/03/16 11:35:41 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline void print_nbr(double num, int fd)
{
    t_ll ipart = (t_ll)num;
    t_ll fpart = (num - (double)ipart) * ft_bpow(10, 6);
    ft_putnbr_fd(ipart, fd);
    if (fpart != 0)
    {
        ft_putchar_fd('.', fd);
        ft_putnbr_fd(fpart, fd);
    }
    ft_putchar_fd('\n', fd);
}

static inline int priority(char c)
{
    if (c == '~') 							return 4;
    if (c == '*' || c == '/') 				return 3;
    if (c == '+' || c == '-' || c== '%') 	return 2;
    if (c == '=') 							return 1;
    return 0;
}

static void get_res(t_stack *operands, char c)
{
    double res;
    double *a, *b;

    if (c == '~')
    {
        *(double *)stack_top(operands) *= -1.;
        return ;
    }

    b = stack_pop(operands);
    a = stack_pop(operands);

    switch (c)
    {
        case '+':
            res = *a + *b;
            break;
        case '-':
            res = *a - *b;
            break;
        case '/':
            if (*b != 0)
                res = *a / *b;
            else
            {
                ft_puterror("division by zero");
                exit(1);
            }
            break;
        case '*':
            res = *a * *b;
            break;
        case '%':
            if (*b != 0)
                res = (int)*a % (int)*b;
            else
            {
                ft_puterror("division by zero");
                exit(1);
            }
            break;
    }
    stack_push(operands, &res);
}

void 	cmd_eval(char **argv, char **env, int fd)
{
    if (!argv[1] || argv[2])
        return ;

    int i;
    char *expr;
    int unary_flag;
    t_stack operands;
    t_stack operations;

    i = 0;
    expr = argv[1];
    unary_flag = 1;
    operands.data = 0;
    operations.data = 0;
    stack_init(&operands, 1, sizeof(double));
    stack_init(&operations, 1, sizeof(char));
    (void)env;
    while (expr[i])
    {
        if (expr[i] == ' ')
            ;
        else if (expr[i] == '(')
        {
            stack_push(&operations, expr + i);
            unary_flag = 1;
        }
        else if (expr[i] == ')')
        {
            while (*(char *)stack_top(&operations) != '(')
                get_res(&operands, *(char *)stack_pop(&operations));
            (void)stack_pop(&operations);
            unary_flag = 0;
        }
        else if (ft_isdigit(expr[i]))
        {
            double num = ft_atof(expr + i);
            stack_push(&operands, &num);
            while (expr[i] && (ft_isdigit(expr[i]) || expr[i] == '.'))
                i++;
            unary_flag = 0;
            i--;
        }
        else
        {
           while (!stack_is_empty(&operations) && !unary_flag && priority(*(char *)stack_top(&operations)) >= priority(expr[i]))
                get_res(&operands, *(char *)stack_pop(&operations));
           if (unary_flag && expr[i] == '-')
           {
               char c = '~';
               stack_push(&operations, &c);
               unary_flag = 0;
           }
           else
           {
               stack_push(&operations, expr + i);
               unary_flag = 0;
           }
        }
        i++;
    }

    while (operations.size)
        get_res(&operands, *(char *)stack_pop(&operations));

    double *res = stack_pop(&operands);
    print_nbr(*res, fd);
    stack_destroy(&operands);
    stack_destroy(&operations);
}
