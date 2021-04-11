# Red - Black Tree
## Red - Black Tree 란
- 레드-블랙 트리는 각각의 노드가 `Red` 나 `Black` 의 색 속성을 가진 이진탐색트리(Binary Search Tree)입니다.

- 탐색, 삽입, 삭제 모두 **O(log n)** 의 시간복잡도가 소요됩니다.

- 7,6,5,4,3,2,1을 순서대로 삽입하여 Binary Search Tree를 만들어보면 다음과 같습니다.
![binarysearchtree](https://nesoy.github.io/assets/posts/20180831/1.png)
    - 1을 찾고자 할 경우 항상 트리의 높이만큼 시간이 필요합니다.
    - 이러한 문제점을 해결하기 위해 나온 자료구조가 [**Balanced Binary Search Tree**](https://jackpot53.tistory.com/17)의 일종인 `Red - Black tree` 입니다.


## Red - Black Tree 정의
Red - Black Tree는 다음 다섯 가지 속성을 만족하는 **이진탐색트리(Binary Search Tree)** 의 일종입니다.
1. 각 노드는 `Red` or `Black`이라는 색깔을 갖는다.

1. Root node 의 색깔은 `Black`이다.
1. 각 leaf node(NIL) 는 `Black`이다.
1. 어떤 노드의 색깔이 `Red`라면 두 개의 children 의 색깔은 모두 `Black` 이다.

    -> 즉, 연속으로 `Red` 노드가 나올 수 없다.
1. 각 노드에 대해서 노드로부터 descendant leaves 까지의 단순 경로는 모두 같은 수의 black nodes 들을 포함하고 있다. 이를 해당 노드의 `Black-Height`라고 한다.

Red - Black Tree 의 예는 다음 그림과 같습니다. 위 다섯가지 속성을 만족하고 있음을 확인할 수 있습니다.

![샘플](https://nesoy.github.io/assets/posts/20180831/2.png)


## Red - Black Tree 특징

- Binary Search Tree 이므로 BST 의 특징을 모두 갖습니다.
- Root node 부터 leaf node 까지의 모든 경로 중 최소 경로와 최대 경로의 크기는 2배 보다 크지 않습니다. 이러한 상태를 `Balanced` 상태라고 합니다.
- 노드의 child 가 없을 경우 child 를 가리키는 포인터는 NIL 값을 저장합니다. 이러한 NIL 들을 leaf node 로 간주합니다. *(NIL을 하나의 객체로 관리하여 메모리를 절약할수 있습니다.)*

## Red - Black Tree 탐색
- Red - Black Tree의 탐색은 Binary Search Tree의 탐색과 동일하게 이루어집니다.

## Red - Black Tree 삽입
- 삽입되는 모든 노드의 색깔은 `Red`로 지정됩니다.
- 1번째 : 8을 삽입

    ![Insert1](https://nesoy.github.io/assets/posts/20180831/4.png)

    - 2번 규칙에 의해 8을 `Black`으로 변경합니다.

- 2번째 : 18을 삽입

    ![Insert2](https://nesoy.github.io/assets/posts/20180831/5.png)

- 3번째 : 5를 삽입

    ![Insert3](https://nesoy.github.io/assets/posts/20180831/6.png)

- 4번째 : 15를 삽입

    ![Insert4](https://nesoy.github.io/assets/posts/20180831/7.png)
    
    - `연속으로 ` `Red` ` 노드가 나올 수 없다.` 4번 규칙을 위반했습니다.
    - 연속된 `Red`가 나온 경우 2가지 방법을 사용합니다.
        1) **Recoloring**

            삽입된 노드의 부모의 형제 노드의 색깔이 `Red`인 경우
        2) **Restructuring**

            삽입된 노드의 부모의 형제 노드의 색깔이 `Black`인 경우, `NULL`인 경우
    - 현재 상황은 15 노드의 부모의 형제 색깔이 `Red`이기 때문에 **Recoloring**으로 진행합니다.
        - 삽입된 노드의 부모와 부모 형제노드를 `Black`으로 부모의 부모노드를 `Red`로 **Recoloring**합니다.
        - 부모의 부모노드가 Root Node인 경우 Root Node인 경우 `Black`인 규칙에 의해 변경되지 않습니다.
            - 부모의 부모노드가 Root node가 아닌 경우 Double `Red`가 다시 발생 할 수 있습니다. *(Recursive manner)*

- 5번째 : 17 삽입

    ![Insert5](https://nesoy.github.io/assets/posts/20180831/8.png)
    
    - 삽입된 노드의 부모의 형제 색깔이 NULL이기 때문에 Restructuring으로 진행합니다.
    - 삽입된 노드, 부모, 부모의 부모(Grand Parent)를 오름차순으로 정렬합니다.
    - 중앙 값을 부모 노드로 만들고 나머지 노드를 자식으로 변환합니다.
    - 부모 노드가 된 노드를 `Black` 나머지 노드를 `Red`로 Recoloring합니다.

- 6번째 : 25 삽입

    ![Insert6](https://nesoy.github.io/assets/posts/20180831/9.png)

    - `연속으로 ` `Red` ` 노드가 나올 수 없다.` 4번 규칙을 위반했습니다.
    - 삽입된 노드의 부모의 형제 색깔이 `Red`인 경우에 해당됩니다.
    - Recoloring으로 규칙을 위반하지 않게 조정합니다.
    - 삽입된 노드의 부모와 부모 형제노드를 `Black`으로 부모의 부모노드를 `Red`로 Recoloring합니다.

- 7번째 : 40 삽입

    ![Insert7](https://nesoy.github.io/assets/posts/20180831/10.png)

    - `연속으로 ` `Red` ` 노드가 나올 수 없다.` 4번 규칙을 위반했습니다.
    - 삽입된 노드의 부모의 형제 색깔이 NULL이기 때문에 Restructuring으로 진행합니다.
        - 삽입된 노드, 부모, 부모의 부모(Grand Parent) 오름차순으로 정렬합니다.
        - 중앙 값을 부모 노드로 만들고 나머지 노드를 자식으로 변환합니다.
        - 부모 노드가 된 노드를 `Black`나머지 노드를 `Red`로 Recoloring합니다.

### Red - Black Tree 삽입 Implementation
삽입하는 원소를 N, N의 부모 노드를 P, P의 부모를 G, N의 삼촌 노드를 U로 나타내기로 하겠습니다.
```c
struct node *grandparent(struct node *n)
{
    if ((n != NULL) && (n->parent != NULL))
        return n->parent->parent;
    else
        return NULL;
}

struct node *uncle(struct node *n)
{
    struct node *g = grandparent(n);
    if (g == NULL)
        return NULL; // No grandparent means no uncle
    if (n->parent == g->left)
        return g->right;
    else
        return g->left;
}
```
N이 루트노드일때
```c
void insert_case1(struct node *n)
{
    if (n->parent == NULL)
        n->color = BLACK;
    else
        insert_case2(n);
}
```
P가 `Black`노드일때
```c
void insert_case2(struct node *n)
{
    if (n->parent->color == BLACK)
        return; /* Tree is still valid */
    else
        insert_case3(n);
}
```
P와 U 둘다 `Red`노드일때
```c
void insert_case3(struct node *n)
{
    struct node *u = uncle(n), *g;

    if ((u != NULL) && (u->color == RED)) {
        n->parent->color = BLACK;
        u->color = BLACK;
        g = grandparent(n);
        g->color = RED;
        insert_case1(g);
    } else {
        insert_case4(n);
    }
}
```
P는 `Red`노드이고 U는 `Black`노드일때, 또한 N은 P의 오른쪽 자식 노드이며, P는 할아버지 노드 G의 왼쪽 자식 노드일때 (Double Rotation)
```c
void insert_case4(struct node *n)
{
    struct node *g = grandparent(n);

    if ((n == n->parent->right) && (n->parent == g->left)) {
        rotate_left(n->parent);
        n = n->left;
    } else if ((n == n->parent->left) && (n->parent == g->right)) {
        rotate_right(n->parent);
        n = n->right;
    }
    insert_case5(n);
}
```
```c
static void rotate_left(struct node *n)
{
    struct node *c = n->right;
    struct node *p = n->parent;

    if (c->left != NULL)
        c->left->parent = n;

    n->right = c->left;
    n->parent = c;
    c->left = n;
    c->parent = p;

    if (p != NULL) {
        if (p->left == n)
            p->left = c;
        else
            p->right = c;
    }
}

static void rotate_right(struct node *n)
{
    struct node *c = n->left;
    struct node *p = n->parent;

    if (c->right != NULL)
        c->right->parent = n;

    n->left = c->right;
    n->parent = c;
    c->right = n;
    c->parent = p;

    if (p != NULL) {
        if (p->right == n)
            p->right = c;
        else
            p->left = c;
    }
}
```
P는 `Red`노드이고 U는 `Black`노드일때, 또한, N이 P의 왼쪽 자식 노드이고, P가 할아버지 노드 G의 왼쪽 자식 노드일때 (Single Rotation)
```c
void insert_case5(struct node *n)
{
    struct node *g = grandparent(n);

    n->parent->color = BLACK;
    g->color = RED;
    if (n == n->parent->left)
        rotate_right(g);
    else
        rotate_left(g);
}
```

## Red - Black Tree 삭제

- 노드를 삭제하기 위해서는 삽입에서 고려했던 규칙들을 모두 고려하여 Rotation을 이용해 삭제 시켜주어야합니다.
- 삭제될 노드의 Child의 갯수에 따라 Rotation 방법도 달라집니다.
- 삭제할 노드의 색이 `Black`이라면 `Black-Height`가 1 감소한 경로에 `Black`노드가 1개 추가 되도록 Rotation하고 Recoloring합니다.
- 삭제할 노드의 색이 `Red`라면 규칙 위반이 일어나지 않으므로 Red-Black Tree가 유지됩니다.(?)


## Reference
1. [RedBlack Tree에 대해](https://nesoy.github.io/articles/2018-08/Algorithm-RedblackTree)
2. [레드-블랙 트리](https://ko.wikipedia.org/wiki/%EB%A0%88%EB%93%9C-%EB%B8%94%EB%9E%99_%ED%8A%B8%EB%A6%AC)
3. [RB tree](https://ratsgo.github.io/data%20structure&algorithm/2017/10/28/rbtree/)
4. Red - Black Tree 알고리즘 Visualization : https://www.cs.usfca.edu/~galles/visualization/RedBlack.html

끝