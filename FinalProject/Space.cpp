//
// Jason Hoffman
// 12/7/2015
// Final Project, CS162

#include "Space.hpp"
#include "Character.hpp"

Space::Space() {
    this->fwd = NULL;
    this->back = NULL;
    this->left = NULL;
    this->right = NULL;
    this->requiresKey = false;
}

Space::~Space() {
}

Space::Space(Space *f, Space *b, Space *l, Space *r) {
    this->fwd = f;
    this->back = b;
    this->left = l;
    this->right = r;
    this->requiresKey = false;
}

void Space::setLocation(Space *f, Space *b, Space *l, Space *r, Character *c, std::string s) {
    this->fwd = f;
    this->back = b;
    this->left = l;
    this->right = r;
    this->character = c;
    this->spaceName = s;
}

void Space::manipulate() {
    std::cout << "Nothing to do here\n";
}

bool Space::getRequiresKey() {
    return this->requiresKey;
}

Space* Space::getBack() {
    if (this->back != NULL) {
        return this->back;
    } else {
        return NULL;
    }
}

Space* Space::getFwd() {
    if (this->fwd != NULL) {
        return this->fwd;
    } else {
        return NULL;
    }
}

Space* Space::getLeft() {
    if (this->left != NULL) {
        return this->left;
    } else {
        return NULL;
    }
}

Space* Space::getRight() {
    if (this->right != NULL) {
        return this->right;
    } else {
        return NULL;
    }
}

std::string Space::getSpaceName() {
    return this->spaceName;
}