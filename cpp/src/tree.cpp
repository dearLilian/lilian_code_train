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

void PrintBTreeIn(BinaryTreeNode* root) {
    if (root == NULL) {
        printf("invalid param");
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
void PrintBTree_no_digui(BinaryTreeNode* root) {
    if (root == NULL) {
        printf("Invalid param");
    }

    stack<BinaryTreeNode*> st;

    //入栈
    st.push(root);
    BinaryTreeNode* p = NULL;
    p = root->m_pLeft;
    while (p != NULL) {
        st.push(p);
        p = p->m_pLeft;
    }

    //出栈
    while (st.size() > 0) {
        
        p = st.top();
        st.pop();
        if (p->m_pLeft == NULL && p->mRight == NULL) {
            printf("%d\n", p->m_nValue);
        } else if (p->m_pRight != NULL) {
            BinaryTreeNode* p_tmp = p->m_pRight;
            st.push(p_tmp);
            while (p_tmp -> m_pLeft != NULL) {
                st.push(p_tmp->m_pLeft);
            }
        }
    }
    
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

    PrintBTreePre(btree);
    

    BinaryTreeNode* pnext = GetNext(btree->m_pRight);
    printf("current node value: %d\n", btree->m_pRight->m_nValue );
    printf("current node value: %d\n", pnext->m_nValue );
    
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
