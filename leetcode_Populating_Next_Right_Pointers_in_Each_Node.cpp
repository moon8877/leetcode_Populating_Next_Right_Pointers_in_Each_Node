/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        return bfs(root);
        
    }
private:
    Node* bfs(Node* root){
        vector<Node*> curNode;
        vector<Node*> nextNode;
        curNode.push_back(root);
        while(curNode.size()!=0){
            for(int i=0;i<curNode.size();++i){
                if(curNode[i]->left){nextNode.push_back(curNode[i]->left);}
                if(curNode[i]->right){nextNode.push_back(curNode[i]->right);}
                if(i==(curNode.size()-1)){
                    curNode[i]->next =NULL;
                }
                else{
                    curNode[i]->next = curNode[i+1];
                }  
            }
            curNode.swap(nextNode);
            nextNode.clear();
        }
        return root;
    }
};
