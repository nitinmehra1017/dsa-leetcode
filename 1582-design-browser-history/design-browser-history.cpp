class Node {
public:
    string data;
    Node* forward;
    Node* back;

    Node() : data(""), forward(nullptr), back(nullptr) {}

    Node(string x) : data(x), forward(nullptr), back(nullptr) {}

    Node(string x, Node* forward, Node* back)
        : data(x), forward(forward), back(back) {}
};


class BrowserHistory {
    Node* current;

public:

    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {

        Node* newNode = new Node(url);

        // Clear forward history
        current->forward = newNode;

        // Connect new node backward
        newNode->back = current;

        // Move current to new page
        current = newNode;
    }

    string back(int steps) {

        while (steps) {

            if (current->back)
                current = current->back;
            else
                break;

            steps--;
        }

        return current->data;
    }

    string forward(int steps) {

        while (steps) {

            if (current->forward)
                current = current->forward;
            else
                break;

            steps--;
        }

        return current->data;
    }
};