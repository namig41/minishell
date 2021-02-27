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
    int *a, *b;
    int res;

    if (c == '~')
    {
        *(int *)stack_top(operands) *= -1;
        return ;
    }
    b = stack_pop(operands);
    a = stack_pop(operands);

    switch (c) {
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
            res = *a % *b;
            break;
    }
    stack_push(operands, &res);
}

void 	cmd_eval(char **argv, char **env, int fd)
{
    if (!argv[1] || argv[2])
        return ;

    t_stack operands;
    t_stack operations;
    char *expr;
    int i;
    int unary_flag;

    (void)env;

    i = 0;
    expr = argv[1];
    unary_flag = 1;
    operands.data = 0;
    operations.data = 0;
    stack_init(&operands, 1, sizeof(int));
    stack_init(&operations, 1, sizeof(char));
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
            int num = ft_atoi(expr + i);
            stack_push(&operands, &num);
            while (expr[i] && ft_isdigit(expr[i]))
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

    int *res = stack_pop(&operands);
    char *s_res = ft_itoa(*res);
    ft_putendl_fd(s_res, fd);
    ft_memdel((void **)&s_res);
    stack_destroy(&operands);
    stack_destroy(&operations);
}
