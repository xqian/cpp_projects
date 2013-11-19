发信人: didiaoge (低调哥), 信区: JobHunting
标  题: Re: 请问如何sort一个linked list？
发信站: BBS 未名空间站 (Sun Nov  3 18:10:16 2013, 美东)

void quick_sort(node *&head, node *&tail) {
    if (!head) return;
    node *lh, *lt, *rh, *rt;
    lh = lt = rh = rt = NULL;
    for (node *p = head->next; p; p = p->next) {
        if (p->val < head->val) {
            if (!lh) lh = lt = p;
            else lt->next = p, lt = p;
        } else {
            if (!rh) rh = rt = p;
            else rt->next = p, rt = p;
        }
    }
    if (lh) lt->next = NULL;
    if (rh) rt->next = NULL;
    quick_sort(lh, lt);
    quick_sort(rh, rt);
    node *p = head;
    p->next = NULL, tail = p;
    if (lh) head = lh, lt->next = p;
    if (rh) p->next = rh, tail = rt;
}

