# include "../../includes/push_swap.h"

int add_value(t_a *a, int value)
{
    t_a *temp;

    temp = a;
    if (temp == NULL)
    {
        a = malloc(sizeof(t_a) * 1);
        a->value = value;
        a->next = NULL;
        return(0);
    }
    while (temp->next != NULL)
    {
        if (temp->value == value)
            return(1);
        temp = temp->next;
    }
    temp->next = malloc(sizeof(t_a) * 1);
    temp->next->value = value;
    temp->next->next = NULL;
    return(0);
}

int check_arv(char **arv, t_a *a)
{
    int value;
    int len1;
    int len2;
    
    *arv++;
    while(*arv != NULL)
    {
        value = ft_atoi(*arv);
        len1 = ft_strlen(*arv);
        *arv = ft_itoa(value);
        len2 = ft_strlen(*arv);
        free(*arv);
        if (len1 != len2)
            return(1);
        if (add_value(a, value) != 0)
            return(1);
        *arv++;
    }
    return(0);
}

void    print(t_a *a)
{
    while(a->next != NULL)
    {
        printf("%d/n", a->value);
        a = a->next;
    }
}

int main (int arc, char **arv)
{
    t_a a;
    t_b *b;

    if (arc == 1)
        return(1);
    if (check_arv(arv, &a) == 1)
        printf("Wrong\n");
    print(&a);
    printf("OK\n");
    return(0);
}