#include <vector>
#include <numeric>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::cout;
using std::iota;
using std::vector;

template <typename T>
void printVec(const vector<T> &vec)
{
    std::copy(cbegin(vec), cend(vec), std::ostream_iterator<T>(cout, ","));
    std::cout << "\n";
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        int val = head->val;
        cout << val << "->";
        head = head->next;
    }
    cout << "\n";
}

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *prev = head;
    ListNode *curr = head->next;
    prev->next = nullptr;
    ListNode *temp = nullptr;

    while (curr != nullptr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

int main()
{
    vector<int> vec(5);
    vector<ListNode> veclns;
    iota(vec.begin(), vec.end(), 1);

    // printVec(vec);

    for (size_t i = 0; i < vec.size(); ++i)
    {
        ListNode ll = ListNode(i);
        veclns.push_back(ll);
    }

    std::reverse(veclns.begin(), veclns.end());

    ListNode *ln = &veclns.back();
    ListNode *head = ln;
    while (!(veclns.empty()))
    {
        veclns.pop_back();

        if (!(veclns.empty()))
        {
            ln->next = &veclns.back();
        }
        else
        {
            ln->next = nullptr;
            break;
        }
        ln = ln->next;
    }

    printLinkedList(head);

    ListNode *reversedLinkedList = reverseList(head);

    printLinkedList(reversedLinkedList);
}