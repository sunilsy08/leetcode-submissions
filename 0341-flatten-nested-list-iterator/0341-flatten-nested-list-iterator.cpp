/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    queue<int>q;
    NestedIterator(vector<NestedInteger> &nestedList) {
        parse(nestedList);
    }

    void parse(vector<NestedInteger> &nestedList){
        for(auto it: nestedList){
            if(!it.isInteger()){
                parse(it.getList());
            } else {
                q.push(it.getInteger());
            }
        }
    }
    
    int next() {
        if(q.size() > 0 ){
            int ans = q.front();
            q.pop();
            return ans;
        }
        return -1;
    }
    
    bool hasNext() {
        return q.size()>0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */