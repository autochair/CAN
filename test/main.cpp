extern "C" {
#include "roboticscape.h"
#include "rc_usefulincludes.h"
}

#include "can_mcp2515_dfs.h"
#include "can_mcp2515.h"

int main(int argc, char** argv) {
  MCP_CAN myCan;

  if (rc_initialize() != 0) {
    printf("Couldn't initialize robotics cape!\n");
    return -1;
  }

  myCan.begin( MCP_16MHz_500kBPS_CFG1 );

  if (rc_cleanup() != 0) {
    printf("Couldn't initialize robotics cape!\n");
    return -1;
  }

  return 0;
}
