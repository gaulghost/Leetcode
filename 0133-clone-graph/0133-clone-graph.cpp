/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

void recur(Node* head, Node* copy, map<int, Node*>& s){
    vector<Node*> copyArr;
    for(int i=0; i<head->neighbors.size(); i++){
        if(s.find(head->neighbors[i]->val) == s.end()){
            Node* copyChild = new Node(head->neighbors[i]->val);
            s[head->neighbors[i]->val] = copyChild;
            recur(head->neighbors[i], copyChild, s);
        }
        copyArr.push_back(s[head->neighbors[i]->val]);
    }
    copy->neighbors = copyArr;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* headClone = new Node(node->val);
        map<int, Node*> s;
        s[node->val] = headClone;
        recur(node, headClone, s);
        return headClone;
    }
};