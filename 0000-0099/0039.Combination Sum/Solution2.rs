impl Solution {
    fn dfs(i: usize, s: i32, candidates: &Vec<i32>, t: &mut Vec<i32>, ans: &mut Vec<Vec<i32>>) {
        if s == 0 {
            ans.push(t.clone());
            return;
        }
        if i >= candidates.len() || s < candidates[i] {
            return;
        }
        Self::dfs(i + 1, s, candidates, t, ans);
        t.push(candidates[i]);
        Self::dfs(i, s - candidates[i], candidates, t, ans);
        t.pop();
    }

    pub fn combination_sum(mut candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        candidates.sort();
        let mut ans = Vec::new();
        Self::dfs(0, target, &candidates, &mut vec![], &mut ans);
        ans
    }
}
