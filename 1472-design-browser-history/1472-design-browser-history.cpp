struct node {
    string data;
    struct node *next;
    struct node *prev;
    node(string x) : data(x), next(NULL), prev(NULL) {}
};

class BrowserHistory {
public:
    node* start = new node("");
    node* cur = start;
    BrowserHistory(string homepage) {
        start->data = homepage;
    }
    
    void visit(string url) {
        node* temp = new node(url);
        cur->next = temp;
        temp->prev = cur;
        cur = cur->next;
    }
    
    string back(int steps) {
        int t = steps;
        while(cur->prev != NULL && t != 0){
            cur = cur->prev;
            t--;
        }
        return cur->data;
    }
    
    string forward(int steps) {
        int t = steps;
        while(cur->next != NULL && t != 0){
            cur = cur->next;
            t--;
        }
        return cur->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */