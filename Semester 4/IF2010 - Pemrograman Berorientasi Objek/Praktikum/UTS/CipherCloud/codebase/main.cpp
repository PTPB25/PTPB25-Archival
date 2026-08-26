#include <iostream>

#include "CloudNode.hpp"
#include "PublicRecord.hpp"
#include "InternalRecord.hpp"
#include "SecureVaultRecord.hpp"
#include "Formatter.hpp"

void testCloudNode()
{
    std::cout << "CLOUD NODE BEHAVIOUR" << std::endl;

    CloudNode nodeA("NodeA", 10);
    std::cout << "NodeA - used GB: " << nodeA.getUsedGB() << ", limit GB: " << nodeA.getLimitGB() << std::endl;
    CloudNode nodeB = nodeA + 5;
    std::cout << "NodeA_backup - used GB: " << nodeB.getUsedGB() << ", limit GB: " << nodeB.getLimitGB() << std::endl;

    CloudNode nodeC("NodeC", 50);
    nodeC = nodeB;
    CloudNode nodeBackup = nodeC;
    std::cout << "NodeC - used GB: " << nodeC.getUsedGB() << ", limit GB: " << nodeC.getLimitGB() << std::endl;
    systemWipe(nodeC);
    std::cout << "NodeC - used GB: " << nodeC.getUsedGB() << ", limit GB: " << nodeC.getLimitGB() << std::endl;
}


void testRecords()
{
    std::cout << "RECORD HIERARCHY BEHAVIOUR" << std::endl;

    PublicRecord pr("Admin", 12345);
    if (pr.calculateClearance() != 0)
    {
        std::cout << "[ERROR] PublicRecord::calculateClearance() gagal di-override secara benar. Seharusnya 0!" << std::endl;
    }
    else
    {
        std::cout << "[PASS] PublicRecord mengembalikan clearance 0." << std::endl;
    }

    InternalRecord ir("DevOps", 12345);
    if (ir.peekSecurity() != 10)
    {
        std::cout << "[ERROR] InternalRecord::peekSecurity() gagal mengkalkulasikan warisan clearance secara benar." << std::endl;
    }
    else
    {
        std::cout << "[PASS] InternalRecord mengembalikan sekuritas operasional yang tepat (10)." << std::endl;
    }

    SecureVaultRecord svr("CEO", 99999);
    std::cout << "[PASS] SecureVaultRecord berhasil dibentuk dan dikompilasi!" << std::endl;
}

int main()
{
    testCloudNode();
    testRecords();
    return 0;
}