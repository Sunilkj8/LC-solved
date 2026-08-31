/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void getNodes(ListNode* head, vector<int>& nodes) {
        ListNode* p = head;
        while (p != nullptr) {
            nodes.push_back(p->val);
            p = p->next;
        }
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nodes;
        vector<int> ans(2);
        vector<int> nodesDistanceIndex;
        getNodes(head, nodes);

        for (int i = 1; i < nodes.size() - 1; i++) {
            if (nodes[i] > nodes[i + 1] && nodes[i] > nodes[i - 1] ||
                nodes[i] < nodes[i - 1] && nodes[i] < nodes[i + 1]) {
                nodesDistanceIndex.push_back(i);
            }
        }
        if(nodesDistanceIndex.size()==0 || nodesDistanceIndex.size()==1)return {-1,-1};
        sort(nodesDistanceIndex.begin(), nodesDistanceIndex.end());
        ans[1] = (nodesDistanceIndex[nodesDistanceIndex.size() - 1]) -
                 (nodesDistanceIndex[0]);
        int minDistance = INT_MAX;
        for (int i=1;i<nodesDistanceIndex.size();i++){
            minDistance=min(minDistance,nodesDistanceIndex[i]-nodesDistanceIndex[i-1]);
        }
        ans[0]=minDistance;

            return ans;
    }
};