/***************************************************************************
 * 
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file tree.cpp
 * @author liwenbao(liwenbao@baidu.com)
 * @date 2019/07/20 12:14:42
 * @version $Revision$ 
 * @brief 
 *  
 **/


#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = NULL;
    root->m_pRight = NULL;
    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *endPreorder) {
            return root;
        } else {
            printf("Invalid param");
        }
    }

    int *rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue) {
        ++rootInorder;
    }
    if (rootInorder == endInorder && *rootInorder != rootValue) {
        printf("Invalid param");
    }
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0) {
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
        root->m_pLeft->m_pParent = root;
    }
    if (leftLength < endPreorder - startPreorder) {
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
        root->m_pRight->m_pParent = root;
    }
    return root;
}

BinaryTreeNode* ReconstructTree(int* preorder, int* inorder, int length) {
    if (preorder == NULL || inorder == NULL || length <= 0) {
        return NULL;
    }

    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

void PrintBTreePre(BinaryTreeNode* root);
void PrintBTreePre(BinaryTreeNode* root) {
    if (root == NULL) {
        printf("Invalid param");
    }

    printf("%d\t", root->m_nValue);
    if (root->m_pLeft != NULL) {
        PrintBTreePre(root->m_pLeft);
    }
    if (root->m_pRight != NULL) {
        PrintBTreePre(root->m_pRight);
    }
}

void PrintBTreePre_nodigui(BinaryTreeNode* root);
void PrintBTreePre_nodigui(BinaryTreeNode* root) {
    if (root == NULL) {
        printf("Invalid param");
    }

    stack<BinaryTreeNode*> st;
    vector<int> res;
    BinaryTreeNode* node = root;

    st.push(node);
    while(!st.empty()) {
        node = st.top();
        st.pop();
        res.push_back(node->m_nValue);
        if (node->m_pRight != NULL) {
            st.push(node->m_pRight);
        }
        if (node->m_pLeft != NULL) {
            st.push(node->m_pLeft);
        }
    }
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ",";
    }
    cout << endl;

}

void PrintBTreeIn(BinaryTreeNode* root);
void PrintBTreeIn(BinaryTreeNode* root) {
    if (root == NULL) {
        printf("invalid param\n");
    }

    if (root->m_pLeft != NULL) {
        PrintBTreeIn(root->m_pLeft);
    }
    printf("%d\t", root->m_nValue);
    if (root->m_pRight != NULL) {
        PrintBTreeIn(root->m_pRight);
    }
}
//中序遍历,非递归方式,需要用栈
void PrintBTree_no_digui(BinaryTreeNode* root);
void PrintBTree_no_digui(BinaryTreeNode* root) {
    if (root == NULL) {
        printf("Invalid param");
    }

    stack<BinaryTreeNode*> st;
    vector<int> res;
    BinaryTreeNode* node = root;

    while(!st.empty() || node) {
        while(node) {
            st.push(node);
            node = node -> m_pLeft;
        }

        if(!st.empty()) {
            node = st.top();
            st.pop();
            res.push_back(node->m_nValue);
            node = node -> m_pRight;
        }
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ",";
    }
    cout << endl;
}

void PrintBTreePost_nodigui(BinaryTreeNode* root);
void PrintBTreePost_nodigui(BinaryTreeNode* root) {
    if (root == NULL) {
        printf("Invalid param");
    }

    stack<BinaryTreeNode*> st;
    vector<int> res;
    BinaryTreeNode* node = root;

    st.push(node);
    while(!st.empty()) {
        node = st.top();
        st.pop();
        res.push_back(node->m_nValue);
        if (node->m_pRight != NULL) {
            st.push(node->m_pRight);
        }
        if (node->m_pLeft != NULL) {
            st.push(node->m_pLeft);
        }
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ",";
    }
    cout << endl;

}
BinaryTreeNode* GetNext(BinaryTreeNode* pNode) {
    if (pNode == NULL) {
        cout << "invalid param" << endl;
        return NULL;
    }
    BinaryTreeNode* pNext = NULL;
    if (pNode -> m_pRight != NULL){
        BinaryTreeNode* p_tmp = pNode->m_pRight;
        while(p_tmp -> m_pLeft != NULL) {
            p_tmp = p_tmp -> m_pLeft;
        }
        pNext = p_tmp;
    } else if (pNode -> m_pParent != NULL){
        BinaryTreeNode* p_tmp = pNode->m_pParent;
        while (p_tmp->m_pParent != NULL && p_tmp->m_pParent->m_pLeft != p_tmp) {
            p_tmp = p_tmp->m_pParent;
        }
        if (p_tmp->m_pParent == NULL) {
            return NULL;
        } else {
            pNext = p_tmp->m_pParent;
        }

    }

    return pNext;
}

int main() {
    int preorder[] = {1,2,4,7,3,5,6,8};
    int inorder[] = {4,7,2,1,5,3,8,6};
    int length = 8;
    BinaryTreeNode* btree = ReconstructTree(preorder, inorder, length);

    
    printf("\npre 递归\n");
    PrintBTreePre(btree);
    printf("\npre 非递归\n");
    PrintBTreePre_nodigui(btree);
    printf("\nin 递归\n");
    PrintBTreeIn(btree);
    printf("\nin 非递归\n");
    PrintBTree_no_digui(btree);
    
    printf("\npost 非递归\n");
    PrintBTreePost_nodigui(btree);
    

    BinaryTreeNode* pnext = GetNext(btree->m_pRight);
    printf("current node value: %d\n", btree->m_pRight->m_nValue );
    printf("next node value: %d\n", pnext->m_nValue );
    
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
