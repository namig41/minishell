/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarmelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:49:55 by lcarmelo          #+#    #+#             */
/*   Updated: 2020/09/02 13:50:01 by lcarmelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void reverse(t_vector *v)
{
    int l;
    int r;

    l = 0;
    r = (int)v->size - 1;
    while (l < r)
    {
        //ft_swap(&vector_get_element(v, l), &vector_get_element(v, r));
        l++;
        r--;
    }
}

char	*plus(char *a, char *b)
{
    char digit;
    char *s_res;
    int num;
    size_t size_a;
    size_t size_b;
    t_vector res;

    num = 0;
    size_a = ft_strlen(a);
    size_b = ft_strlen(b);
    res.data = 0;
    vector_init(&res, ft_max(size_a, size_b) + 1, sizeof(char));
    while (size_a || size_b)
    {
        if (size_a) num += a[size_a];
        if (size_b) num += b[size_b];
        digit = num % 10;
        vector_push_back_data(&res, &digit);
        num /= 10;
        size_a--, size_b--;
    }
    if (num)
    {
        digit = num % 10;
        vector_push_back_data(&res, &digit);
    }
    reverse(&res);
    s_res = (char *)res.data;
    return s_res;
}

char	*minus(char *a, char *b)
{
    return 0;
}

char    *mult(char *a, char *b)
{
    char digit;
    char *s_res;
    int num;
    size_t j;
    size_t size_a;
    size_t size_b;
    t_vector res;

    j = 0;
    num = 0;
    size_a = ft_strlen(a) - 1;
    size_b = ft_strlen(b) - 1;
    res.data = 0;
    vector_init(&res, size_a + size_b + 1, sizeof(char));
    while (size_a)
    {
        j = size_b;
        while (j)
        {
            num += a[size_a] * b[size_b];
            digit = num % 10;
            vector_push_back_data(&res, &digit);
            num /= 10;
            j--;
        }
        size_a--;
    }
    if (num)
    {
        digit = num % 10;
        vector_push_back_data(&res, &digit);
    }
    reverse(&res);
    s_res = (char *)res.data;
    return s_res;
}

char	*sdiv(char *a, char *b)
{
    return 0;
}
