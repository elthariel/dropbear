// Will run in a container, no inetd
#define INETD_MODE 0

// Not targetted at embedded code
#define DROPBEAR_SMALL_CODE 0
#define DROPBEAR_CLI_REMOTETCPFWD 0

// Disable agent forwarding
#define DROPBEAR_SVR_AGENTFWD 0
#define DROPBEAR_CLI_AGENTFWD 0
