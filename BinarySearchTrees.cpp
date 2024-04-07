#include <iostream>
#include "BinarySearchTree.h"
#include <sstream>


void testInsertNode() {
    std::cout << "test insertNode()\n";
    BinarySearchTree<int> tree;
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(4);

    tree.output(std::cout);
    std::cout << "\n";

    // Output: 1 1 1 1 1 0
    std:: cout << tree.searchKeyIterative(5) << " " << tree.searchKeyIterative(3) << " " << tree.searchKeyIterative(7) << " " << tree.searchKeyIterative(2) << 
        " " << tree.searchKeyIterative(4) << " " << tree.searchKeyIterative(10) << "\texpected: 1 1 1 1 1 0" << std::endl;
}

void testDeleteNode() {
    std::cout << "test deleteNode()\n";
    BinarySearchTree<int> tree;
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(4);

    tree.output(std::cout);
    std::cout << "\n";

    std::cout << "delete 3\n";
    tree.deleteNode(3);
    // Output: 0
    std::cout << tree.searchKeyIterative(3) << "\t\texpected: 0\n";

    // Output: 5(3(2,null),7)
    tree.output(std::cout);
    std::cout << "\texpected: 5(3(2,null),7)" << std::endl;

    //try delete 10
    std::cout << "delete 10\n";
    tree.deleteNode(10);
    tree.output(std::cout);
    std::cout << std::endl;
}

void testGetNumberOfNodes() {
    std::cout << "test getNumberOfNodes()\n";
    BinarySearchTree<int> tree;
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(4);

    tree.output(std::cout);
    std::cout << "\n";

    // Output: 5
    std::cout << tree.getNumberOfNodes() << "\t\texpected: 5\n";

    std::cout << "delete 3\n";
    tree.deleteNode(3);

    // Output: 4
    std::cout << tree.getNumberOfNodes() << "\t\texpected: 4" << "\n";

}

void testGetHeight() {
    std::cout << "test getHeight()\n";
    BinarySearchTree<int> tree;

    tree.insertNode(5);
    tree.insertNode(3);

    tree.output(std::cout);
    std::cout << "\n";

    // Output: 2
    std::cout << tree.getHeight() << "\t\texpected: 2" << std::endl;

    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(4);

    tree.output(std::cout);
    std::cout << "\n";

    // Output: 3
    std::cout << tree.getHeight() << "\t\texpected: 3" << std::endl;
}

void testInorderWalkIterative() {
    std::cout << "test inorderWalkIterative()\n";
    BinarySearchTree<int> tree;
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(4);

    tree.output(std::cout);
    std::cout << "\n";

    std::ostringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
   tree.inorderWalkIterative();
    std::cout.rdbuf(coutbuf);

    std::cout << out.str() << "\texpected: 2 3 4 5 7 " << std::endl;
}

void testInorderWalk() {
    std::cout << "test inorderWalk()\n";
    BinarySearchTree<int> tree;
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(4);

    tree.output(std::cout);
    std::cout << "\n";

    std::ostringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    tree.inorderWalk();
    std::cout.rdbuf(coutbuf);

    std::cout << out.str() << "\texpected: 2 3 4 5 7 " << std::endl;
}

void testWalkByLevels() {
    std::cout << "test walkByLevels()\n";
    BinarySearchTree<int> tree;
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(4);

    tree.output(std::cout);
    std::cout << "\n";

    std::ostringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    tree.walkByLevels();
    std::cout.rdbuf(coutbuf);

    std::cout << out.str() << "\texpected: 5 3 7 2 4 " << std::endl;
}

void testIsSimilar() {
    std::cout << "test isSimilar()\n";
    BinarySearchTree<int> tree1;
    tree1.insertNode(5);
    tree1.insertNode(3);
    tree1.insertNode(7);
    tree1.insertNode(2);
    tree1.insertNode(4);

    BinarySearchTree<int> tree2;
    tree2.insertNode(50);
    tree2.insertNode(30);
    tree2.insertNode(70);
    tree2.insertNode(20);
    tree2.insertNode(40);

    std::cout << "tree1:\t";
    tree1.output(std::cout);
    std::cout << "\n";

    std::cout << "tree2:\t";
    tree2.output(std::cout);
    std::cout << "\n";

    BinarySearchTree<int> tree3;
    tree3.insertNode(5);
    tree3.insertNode(3);
    tree3.insertNode(7);
    tree3.insertNode(2);
    tree3.insertNode(4);

    std::cout << "tree3:\t";
    tree3.output(std::cout);
    std::cout << "\n";

    std::cout << "tree1 Similar tree2: " << tree1.isSimilar(tree2) << "\t\texpected: 0\n";
    std::cout << "tree1 Similar tree3: " << tree1.isSimilar(tree3) << "\t\texpected: 1" << std::endl;
}

void testIsIdenticalKey() {
    std::cout << "test isIdenticalKey()\n";
    BinarySearchTree<int> tree1;
    tree1.insertNode(5);
    tree1.insertNode(3);
    tree1.insertNode(7);
    tree1.insertNode(2);
    tree1.insertNode(4);

    BinarySearchTree<int> tree2;
    tree2.insertNode(3);
    tree2.insertNode(5);
    tree2.insertNode(7);
    tree2.insertNode(2);
    tree2.insertNode(4);

    std::cout << "tree1:\t";
    tree1.output(std::cout);
    std::cout << "\n";

    std::cout << "tree2:\t";
    tree2.output(std::cout);
    std::cout << "\n";

    std::cout << "tree1 IdenticalKey tree2: " << tree1.isIdenticalKey(tree2) << "\texpected: 1" << std::endl;
}

int main() {
    testInsertNode();
    std::cout << "\n\n";
    testDeleteNode();
    std::cout << "\n\n";
    testGetNumberOfNodes();
    std::cout << "\n\n";
    testGetHeight();
    std::cout << "\n\n";
    testInorderWalkIterative();
    std::cout << "\n\n";
    testInorderWalk();
    std::cout << "\n\n";
    testWalkByLevels();
    std::cout << "\n\n";
    testIsSimilar();
    std::cout << "\n\n";
    testIsIdenticalKey();

    return 0;
}


//int main() {
//    BinarySearchTree<int> tree;
//    tree.insertNode(5);
//    tree.insertNode(3);
//    tree.insertNode(7);
//    tree.insertNode(2);
//    tree.insertNode(4);
//
//    std::cout << "Search 3: " << tree.searchKeyIterative(3) << std::endl;  // Output: Search 3: 1
//    std::cout << "Search 10: " << tree.searchKeyIterative(10) << std::endl; // Output: Search 10: 0
//
//    tree.output(std::cout);
//    std::cout << "\n";
//
//    tree.deleteNode(3);
//    std::cout << "Search 3 after erase: " << tree.searchKeyIterative(3) << std::endl; // Output: Search 3 after erase: 0
//
//    tree.output(std::cout);
//
//    tree.insertNode(8);
//    return 0;
//}