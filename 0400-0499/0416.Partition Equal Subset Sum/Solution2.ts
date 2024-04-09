function canPartition(nums: number[]): boolean {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s % 2 === 1) {
        return false;
    }
    const m = s >> 1;
    const f: boolean[] = Array(m + 1).fill(false);
    f[0] = true;
    for (const x of nums) {
        for (let j = m; j >= x; --j) {
            f[j] = f[j] || f[j - x];
        }
    }
    return f[m];
}
