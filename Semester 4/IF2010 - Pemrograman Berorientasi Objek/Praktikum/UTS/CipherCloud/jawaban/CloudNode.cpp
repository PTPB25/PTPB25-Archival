#include "CloudNode.hpp"

CloudNode::CloudNode(string name, int limit) : server_name(name), limit_gb(limit){ 
    used_gb = 0; 
    Formatter::printCtor(server_name);
}

CloudNode::CloudNode(CloudNode &other) : server_name(other.server_name + "_backup"), limit_gb(other.limit_gb){ 
    used_gb = 0; 
    Formatter::printCCtor(server_name);
}

CloudNode& CloudNode::operator=(CloudNode &other){
    this->used_gb = other.used_gb + 2 > limit_gb ? limit_gb : other.used_gb + 2;
    Formatter::printAssign(server_name);
    return *this;
}

CloudNode::~CloudNode(){
    Formatter::printDtor(server_name);
}

CloudNode& CloudNode::operator+(int other){
    limit_gb += other;
    return *this;
}

CloudNode& CloudNode::operator-(int other){
    used_gb -= other;
    if(used_gb < 0) used_gb = 0;
    return *this;
}

void systemWipe(CloudNode &node){
    node.limit_gb = 0;
    node.used_gb = 0;
}