#include<queue>

int height(Node* root) {

    queue<Node *> q;
    q.push(root);
    q.push(nullptr); //push a nullptr to mark the ending of a level
    int level = -1;

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        //children of all nodes before nullptr have been pushed, so push a nullptr to mark the ending of a level
        if(temp == nullptr)
        {
            if(!q.empty())
            {
                q.push(nullptr);
            }
            level++;
        }
        else
        {
            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
    return level;
}