class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> s1 = convert(nums1);
        Set<Integer> s2 = convert(nums2);
        List<Integer> l1 = new ArrayList<>();
        List<Integer> l2 = new ArrayList<>();
        for (int v : s1) {
            if (!s2.contains(v)) {
                l1.add(v);
            }
        }
        for (int v : s2) {
            if (!s1.contains(v)) {
                l2.add(v);
            }
        }
        return List.of(l1, l2);
    }

    private Set<Integer> convert(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for (int v : nums) {
            s.add(v);
        }
        return s;
    }
}