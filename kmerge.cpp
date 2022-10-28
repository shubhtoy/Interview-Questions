public static class NodeComparator implements Comparator<ListNode> {
    @Override
    public int compare(ListNode o1, ListNode o2) {
        return o1.val - o2.val;
    }
}
