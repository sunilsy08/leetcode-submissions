class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq
            = new PriorityQueue<Integer>(
                Collections.reverseOrder());
        for(int gift : gifts) {
            pq.add(gift);
        }
        long ans = 0;

        for(int i=0; i<k; i++) {
            int curr = pq.poll();
            int num = (int)Math.sqrt(curr);
            pq.add(num);
        }
        Object[] remaining = pq.toArray();
        for(Object num : remaining) {
            ans += (int)num;
        }
        return ans;
    }
}