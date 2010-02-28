/*
  Copyright 2009, jimmikaelkael
  Licenced under Academic Free License version 3.0
  Review OpenUsbLd README & LICENSE files for further details.
*/

#ifndef __SMB_H__
#define __SMB_H__

// SMB Headers are always 32 bytes long
#define SMB_HDR_SIZE 32

// FLAGS field bitmasks
#define SMB_FLAGS_SERVER_TO_REDIR 		0x80
#define SMB_FLAGS_REQUEST_BATCH_OPLOCK 	0x40
#define SMB_FLAGS_REQUEST_OPLOCK		0x20
#define SMB_FLAGS_CANONICAL_PATHNAMES	0x10
#define SMB_FLAGS_CASELESS_PATHNAMES	0x08
#define SMB_FLAGS_RESERVED 				0x04
#define SMB_FLAGS_CLIENT_BUF_AVAIL 		0x02
#define SMB_FLAGS_SUPPORT_LOCKREAD 		0x01
#define SMB_FLAGS_MASK 					0x00

// FLAGS2 field bitmasks
#define SMB_FLAGS2_UNICODE_STRING		0x8000
#define SMB_FLAGS2_32BIT_STATUS			0x4000
#define SMB_FLAGS2_READ_IF_EXECUTE		0x2000
#define SMB_FLAGS2_DFS_PATHNAME			0x1000
#define SMB_FLAGS2_EXTENDED_SECURITY	0x0800	
#define SMB_FLAGS2_RESERVED_01			0x0400
#define SMB_FLAGS2_RESERVED_02			0x0200
#define SMB_FLAGS2_RESERVED_03			0x0100
#define SMB_FLAGS2_RESERVED_04			0x0080
#define SMB_FLAGS2_IS_LONG_NAME			0x0040
#define SMB_FLAGS2_RESERVED_05			0x0020
#define SMB_FLAGS2_RESERVED_06			0x0010
#define SMB_FLAGS2_RESERVED_07			0x0008
#define SMB_FLAGS2_SECURITY_SIGNATURE	0x0004
#define SMB_FLAGS2_EAS					0x0002
#define SMB_FLAGS2_KNOWS_LONG_NAMES		0x0001
#define SMB_FLAGS2_MASK					0xf847

// Field offsets
#define SMB_OFFSET_CMD 		 		4
#define SMB_OFFSET_NTSTATUS	 		5
#define SMB_OFFSET_ECLASS	 		5
#define SMB_OFFSET_ECODE	 		7
#define SMB_OFFSET_FLAGS	 		9
#define SMB_OFFSET_FLAGS2			10 			
#define SMB_OFFSET_EXTRA			12
#define SMB_OFFSET_TID				24
#define SMB_OFFSET_PID				26
#define SMB_OFFSET_UID				28
#define SMB_OFFSET_MID				30
#define SMB_OFFSET_WORDCOUNT		32
#define SMB_OFFSET_ANDX_CMD			33
#define SMB_OFFSET_ANDX_RESERVED	34
#define SMB_OFFSET_ANDX_OFFSET		35

// Transaction2 Request Field offsets
#define SMB_TRANS2_REQ_OFFSET_TOTALPARAMCOUNT 	33
#define SMB_TRANS2_REQ_OFFSET_TOTALDATACOUNT	35
#define SMB_TRANS2_REQ_OFFSET_MAXPARAMCOUNT		37
#define SMB_TRANS2_REQ_OFFSET_MAXDATACOUNT		39
#define SMB_TRANS2_REQ_OFFSET_MAXSETUPCOUNT		41
#define SMB_TRANS2_REQ_OFFSET_RESERVED			42
#define SMB_TRANS2_REQ_OFFSET_FLAGS				43
#define SMB_TRANS2_REQ_OFFSET_TIMEOUT			45
#define SMB_TRANS2_REQ_OFFSET_RESERVED2			49
#define SMB_TRANS2_REQ_OFFSET_PARAMCOUNT		51
#define SMB_TRANS2_REQ_OFFSET_PARAMOFFSET		53
#define SMB_TRANS2_REQ_OFFSET_DATACOUNT			55
#define SMB_TRANS2_REQ_OFFSET_DATAOFFSET		57
#define SMB_TRANS2_REQ_OFFSET_SETUPCOUNT		59
#define SMB_TRANS2_REQ_OFFSET_RESERVED3			60
#define SMB_TRANS2_REQ_OFFSET_SETUP0			61

// Transaction2 Response Field offsets
#define SMB_TRANS2_RSP_OFFSET_TOTALPARAMCOUNT 	33
#define SMB_TRANS2_RSP_OFFSET_TOTALDATACOUNT	35
#define SMB_TRANS2_RSP_OFFSET_RESERVED			37
#define SMB_TRANS2_RSP_OFFSET_PARAMCOUNT		39
#define SMB_TRANS2_RSP_OFFSET_PARAMOFFSET		41
#define SMB_TRANS2_RSP_OFFSET_PARAMDISPLACEMENT 43
#define SMB_TRANS2_RSP_OFFSET_DATACOUNT			45
#define SMB_TRANS2_RSP_OFFSET_DATAOFFSET		47
#define SMB_TRANS2_RSP_OFFSET_DATADISPLACEMENT	49
#define SMB_TRANS2_RSP_OFFSET_SETUPCOUNT		51
#define SMB_TRANS2_RSP_OFFSET_RESERVED2			52
#define SMB_TRANS2_RSP_OFFSET_BYTECOUNT			53
#define SMB_TRANS2_RSP_OFFSET_PAD				55

// SMB File Attributes Encoding (16-bit)
#define ATTR_READONLY		0x01
#define ATTR_HIDDEN			0x02
#define ATTR_SYSTEM			0x04
#define ATTR_VOLUME			0x08
#define ATTR_DIRECTORY		0x10
#define ATTR_ARCHIVE		0x20

// SMB Extended File Attributes Encoding (32-bit)
#define EXT_ATTR_READONLY		0x001
#define EXT_ATTR_HIDDEN			0x002
#define EXT_ATTR_SYSTEM			0x004
#define EXT_ATTR_DIRECTORY		0x010
#define EXT_ATTR_ARCHIVE		0x020
#define EXT_ATTR_NORMAL			0x080
#define EXT_ATTR_TEMPORARY		0x100
#define EXT_ATTR_COMPRESSED		0x800

// SMB Information Level
#define SMB_INFO_STANDARD					0x001
#define SMB_INFO_QUERY_EA_SIZE				0x002
#define SMB_INFO_QUERY_EAS_FROM_LIST		0x003
#define SMB_FIND_FILE_DIRECTORY_INFO		0x101	
#define SMB_FIND_FILE_FULL_DIRECTORY_INFO	0x102
#define SMB_FIND_FILE_NAMES_INFO			0x103
#define SMB_FIND_FILE_BOTH_DIRECTORY_INFO	0x104
#define SMB_FIND_FILE_UNIX					0x202

// SMB Search Flags
#define CLOSE_SEARCH_AFTER_REQUEST	0x01
#define CLOSE_SEARCH_IF_EOS			0x02
#define RESUME_SEARCH				0x04
#define CONTINUE_SEARCH				0x08
#define BACKUP_INTENT_SEARCH		0x10

// SMB Server Capabilities
#define SERVER_CAP_EXTENDED_SECURITY		0x80000000
#define SERVER_CAP_COMPRESSED_DATA			0x40000000
#define SERVER_CAP_BULK_TRANSFER			0x20000000
#define SERVER_CAP_UNIX						0x00800000
#define SERVER_CAP_LARGE_WRITEX				0x00008000
#define SERVER_CAP_LARGE_READX				0x00004000
#define SERVER_CAP_INFOLEVEL_PASSTHROUGH	0x00002000
#define SERVER_CAP_DFS						0x00001000
#define SERVER_CAP_NT_FIND					0x00000200
#define SERVER_CAP_LOCK_AND_READ			0x00000100
#define SERVER_CAP_LEVEL_II_OPLOCKS			0x00000080
#define SERVER_CAP_STATUS32					0x00000040
#define SERVER_CAP_RPC_REMOTE_APIS			0x00000020
#define SERVER_CAP_NT_SMBS					0x00000010
#define SERVER_CAP_LARGE_FILES				0x00000008
#define SERVER_CAP_UNICODE					0x00000004
#define SERVER_CAP_MPX_MODE					0x00000002
#define SERVER_CAP_RAW_MODE					0x00000001

// SMB Client Capabilities
#define CLIENT_CAP_EXTENDED_SECURITY		0x80000000
#define CLIENT_CAP_LARGE_READX				0x00004000
#define CLIENT_CAP_NT_FIND					0x00000200
#define CLIENT_CAP_LEVEL_II_OPLOCKS			0x00000080
#define CLIENT_CAP_STATUS32					0x00000040
#define CLIENT_CAP_NT_SMBS					0x00000010
#define CLIENT_CAP_LARGE_FILES				0x00000008
#define CLIENT_CAP_UNICODE					0x00000004

// Security Modes
#define NEGOCIATE_SECURITY_SIGNATURES_REQUIRED	0x08
#define NEGOCIATE_SECURITY_SIGNATURES_ENABLED	0x04
#define NEGOCIATE_SECURITY_CHALLENGE_RESPONSE	0x02
#define NEGOCIATE_SECURITY_USER_LEVEL			0x01

// SMB Commands
#define SMB_COM_CREATE_DIRECTORY		0x00
#define SMB_COM_DELETE_DIRECTORY		0x01
#define SMB_COM_OPEN					0x02
#define SMB_COM_CREATE					0x03
#define SMB_COM_CLOSE					0x04
#define SMB_COM_FLUSH					0x05	
#define SMB_COM_DELETE					0x06
#define SMB_COM_RENAME					0x07
#define SMB_COM_QUERY_INFORMATION		0x08
#define SMB_COM_SET_INFORMATION			0x09
#define SMB_COM_READ					0x0a
#define SMB_COM_WRITE					0x0b
#define SMB_COM_LOCK_BYTE_RANGE			0x0c
#define SMB_COM_UNLOCK_BYTE_RANGE		0x0d
#define SMB_COM_CREATE_TEMPORARY		0x0e
#define SMB_COM_CREATE_NEW				0x0f
#define SMB_COM_CHECK_DIRECTORY			0x10
#define SMB_COM_PROCESS_EXIT			0x11
#define SMB_COM_SEEK					0x12
#define SMB_COM_LOCK_AND_READ			0x13
#define SMB_COM_WRITE_AND_UNLOCK		0x14
#define SMB_COM_READ_RAW				0x1a
#define SMB_COM_READ_MPX				0x1b
#define SMB_COM_READ_MPX_SECONDARY		0x1c
#define SMB_COM_WRITE_RAW				0x1d
#define SMB_COM_WRITE_MPX				0x1e
#define SMB_COM_WRITE_MPX_SECONDARY		0x1f	
#define SMB_COM_WRITE_COMPLETE			0x20
#define SMB_COM_QUERY_SERVER			0x21
#define SMB_COM_SET_INFORMATION2		0x22
#define SMB_COM_QUERY_INFORMATION2		0x23
#define SMB_COM_LOCKING_ANDX			0x24
#define SMB_COM_TRANSACTION				0x25
#define SMB_COM_TRANSACTION_SECONDARY	0x26
#define SMB_COM_IOCTL					0x27
#define SMB_COM_IOCTL_SECONDARY			0x28
#define SMB_COM_COPY					0x29
#define SMB_COM_MOVE					0x2a
#define SMB_COM_ECHO					0x2b
#define SMB_COM_WRITE_AND_CLOSE			0x2c
#define SMB_COM_OPEN_ANDX				0x2d
#define SMB_COM_READ_ANDX				0x2e
#define SMB_COM_WRITE_ANDX				0x2f
#define SMB_COM_NEW_FILE_SIZE			0x30
#define SMB_COM_CLOSE_AND_TREE_DISC		0x31	
#define SMB_COM_TRANSACTION2			0x32
#define SMB_COM_TRANSACTION2_SECONDARY	0x33
#define SMB_COM_FIND_CLOSE2				0x34
#define SMB_COM_FIND_NOTIFY_CLOSE		0x35
#define SMB_COM_TREE_CONNECT			0x70
#define SMB_COM_TREE_DISCONNECT			0x71
#define SMB_COM_NEGOCIATE				0x72
#define SMB_COM_SESSION_SETUP_ANDX		0x73
#define SMB_COM_LOGOFF_ANDX				0x74
#define SMB_COM_TREE_CONNECT_ANDX		0x75
#define SMB_COM_QUERY_INFORMATION_DISK	0x80
#define SMB_COM_SEARCH					0x81
#define SMB_COM_FIND					0x82
#define SMB_COM_FIND_UNIQUE				0x83
#define SMB_COM_FIND_CLOSE				0x84
#define SMB_COM_NT_TRANSACT				0xa0
#define SMB_COM_NT_TRANSACT_SECONDARY	0xa1
#define SMB_COM_NT_CREATE_ANDX			0xa2
#define SMB_COM_NT_CANCEL				0xa4
#define SMB_COM_NT_RENAME				0xa5
#define SMB_COM_OPEN_PRINT_FILE			0xc0
#define SMB_COM_WRITE_PRINT_FILE		0xc1
#define SMB_COM_CLOSE_PRINT_FILE		0xc2
#define SMB_COM_GET_PRINT_QUEUE			0xc3
#define SMB_COM_READ_BULK				0xd8
#define SMB_COM_WRITE_BULK				0xd9
#define SMB_COM_WRITE_BULK_DATA			0xda
#define SMB_COM_NONE					0xff

// Setup[0] Transaction2 Subcommands
#define TRANS2_OPEN2					0x00
#define TRANS2_FIND_FIRST2				0x01
#define TRANS2_FIND_NEXT2				0x02
#define TRANS2_QUERY_FS_INFORMATION		0x03
#define TRANS2_SET_FS_INFORMATION		0x04
#define TRANS2_QUERY_PATH_INFORMATION	0X05
#define TRANS2_SET_PATH_INFORMATION		0x06
#define TRANS2_QUERY_FILE_INFORMATION	0x07
#define TRANS2_SET_FILE_INFORMATION		0x08
#define TRANS2_FSCTL					0x09
#define TRANS2_IOCTL2					0x0a
#define TRANS2_FIND_NOTIFY_FIRST		0x0b
#define TRANS2_FIND_NOTIFY_NEXT			0x0c
#define TRANS2_CREATE_DIRECTORY			0x0d
#define TRANS2_SESSION_SETUP			0x0e
#define TRANS2_GET_DFS_REFERRAL			0x10
#define TRANS2_REPORT_DFS_INCONSISTENCY	0x11

// DOS Error Class
#define DOS_ECLASS_SUCCESS 		0x00

// NT Status
#define STATUS_SUCCESS					0x00000000
#define STATUS_NO_MEDIA_IN_DEVICE		0xc0000013

typedef struct _smb_time {
	u32 timeLow;
	u32 timeHigh;
} smb_time;
									
// function prototypes
int rawTCP_SetSessionHeader(u32 size);  // Write Session Service header 
int rawTCP_GetSessionHeader(void); 		// Read Session Service header

int smb_NegociateProtocol(char *SMBServerIP, int SMBServerPort, char *dialect); // process a Negociate Procotol message
int smb_SessionSetupTreeConnect(char *User, char *share_name); 		// process a Session Setup message, for NT LM 0.12 dialect, Non Extended Security negociated
int smb_OpenAndX(char *filename, u16 *FID, u32 *filesize); 			// process a Open AndX message
int smb_ReadAndX(u16 FID, u32 offset, void *readbuf, u16 nbytes); 	// process a Read AndX message
int smb_Close(u16 FID);												// process a Close message
int smb_Disconnect(void);

#define MAX_SMB_BUF 	15360 // must fit on u16 !!! 

#endif
