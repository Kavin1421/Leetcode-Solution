struct NumArray {
    s: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumArray {
    fn new(mut nums: Vec<i32>) -> Self {
        let n = nums.len();
        let mut s = vec![0; n + 1];
        for i in 0..n {
            s[i + 1] = s[i] + nums[i];
        }
        Self { s }
    }

    fn sum_range(&self, left: i32, right: i32) -> i32 {
        self.s[(right + 1) as usize] - self.s[left as usize]
    }
}/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray::new(nums);
 * let ret_1: i32 = obj.sum_range(left, right);
 */
