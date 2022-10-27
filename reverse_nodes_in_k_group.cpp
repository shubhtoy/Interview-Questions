 int count = 0;
    while (count != k && curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    head->next = reverseKGroup(forward, k);
    return prev;
}
