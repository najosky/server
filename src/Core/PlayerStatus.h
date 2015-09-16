//----------------------------------------------------------------------
//
// Filename    : PlayerStatus.h
// Written By  : Reiot
// Description : �÷��̾� ���¿� ���� ��� ������ ��Ŷ ���̵��� ���� ����
//
//----------------------------------------------------------------------

#ifndef __PLAYER_STATUS_H__
#define __PLAYER_STATUS_H__

enum PlayerStatus {

#if defined(__GAME_CLIENT__)

	//----------------------------------------------------------------------
	// ClientPlayer ��ü�� ������ ����
	// Next Packets : NONE
	//----------------------------------------------------------------------
	CPS_NONE ,

	//----------------------------------------------------------------------
	// �α��� ������ �α��� ������ ������ ��
	// Next Packets : LCLoginOK, LCLoginError
	//----------------------------------------------------------------------
	CPS_BEGIN_SESSION ,

	//----------------------------------------------------------------------
	// CLLogin �� ���� ����
	// Next Packets : LCLoginOK, LCLoginError
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_LOGIN ,

	//----------------------------------------------------------------------
	// CLQueryPlayerID �� ���� ����
	// Next Packets : LCQueryResultPlayerID
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_QUERY_PLAYER_ID,

	//----------------------------------------------------------------------
	// CLRegisterPlayer �� ���� ����
	// Next Packets : LCRegisterPlayerOK, LCRegisterPlayerError
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_REGISTER_PLAYER ,

	//----------------------------------------------------------------------
	// CLGetPCList ��Ŷ�� ���� ����
	// Next Packets : LCPCList
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_GET_PC_LIST ,

	//----------------------------------------------------------------------
	// CLCreatePC �� ���� ����
	// Next Packets : LCCreatePCOK
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_CREATE_PC ,

	//----------------------------------------------------------------------
	// CLDeletePC �� ���� ����
	// Next Packets : LCDeletePCOK, LCDeletePCError
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_DELETE_PC ,

	//----------------------------------------------------------------------
	// CLSelectPC �� ���� ����
	// Next Packets : LCSelectPCOK, LCSelectPCError
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_SELECT_PC ,

	//----------------------------------------------------------------------
	// ���� ������ CGConnect ��Ŷ�� ������.
	// Next Packets : GCUpdateInfo
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CG_CONNECT ,

	//----------------------------------------------------------------------
	// �ε��� ���� ������ ��ٸ���.
	// Next Packets : NONE
	//----------------------------------------------------------------------
	CPS_WAITING_FOR_LOADING ,

	//----------------------------------------------------------------------
	// CGReady ��Ŷ�� ���� ��, �����󿡼� �ڽ��� ��ġ�� �����Ǳ⸦ ��ٸ���.
	// Next Packets : GCSetPosition
	//----------------------------------------------------------------------
	CPS_WAITING_FOR_GC_SET_POSITION ,

	//----------------------------------------------------------------------
	// �Ϲ����� ���� ����
	//----------------------------------------------------------------------
	CPS_NORMAL ,

	//----------------------------------------------------------------------
	// LOGOUT�� CGReconnectLogin
	//----------------------------------------------------------------------
	CPS_WAITING_FOR_GC_RECONNECT_LOGIN ,

	//----------------------------------------------------------------------
	// �α���/���� �������� ���� ����
	//----------------------------------------------------------------------
	CPS_END_SESSION ,

	/*
	//----------------------------------------------------------------------
	// ���� �Խ��� ����
	//----------------------------------------------------------------------
	
	//----------------------------------------------------------------------
	// CPS_AFTER_SENDING_CL_SELECT_BOARD
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_SELECT_BOARD,

	//----------------------------------------------------------------------
	// CPS_AFTER_SENDING_CL_WRITE_TEXT
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_WRITE_CONTENT,

	//----------------------------------------------------------------------
	// CPS_AFTER_SENDING_CL_SELECT_TEXT
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_SELECT_TEXT,

	//----------------------------------------------------------------------
	// CPS_AFTER_SENDING_CL_RELPLY_CONTENT
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_REPLY_CONTENT,

	//----------------------------------------------------------------------
	// CPS_AFTER_SENDING_CL_SEND_PASSWORD
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_SEND_PASSWORD,

	//----------------------------------------------------------------------
	// CPS_AFTER_SENDING_CL_MODIFY_CONTENT
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_MODIFY_CONTENT,
	       
	//----------------------------------------------------------------------
	// CPS_AFTER_SENDING_CL_PREV_PAGE
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_PREV_PAGE,
	    
	//----------------------------------------------------------------------
	// CPS_AFTER_SENDING_CL_NEXT_PAGE
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_NEXT_PAGE,

	//----------------------------------------------------------------------
	// CPS_AFTER_SENDING_CL_SELECT_LIST
	//----------------------------------------------------------------------
	CPS_AFTER_SENDING_CL_SELECT_LIST,
	//----------------------------------------------------------------------
	// ���� �Խ��� ���
	//----------------------------------------------------------------------
	*/
	
#elif defined(__LOGIN_SERVER__)

	//----------------------------------------------------------------------
	// LoginPlayer ��ü�� ������ ����
	// Next Packets : NONE
	//----------------------------------------------------------------------
	LPS_NONE ,

	//----------------------------------------------------------------------
	// �α��� ������ ���� ���� ����
	// Next Packets : CLLogin
	//----------------------------------------------------------------------
	LPS_BEGIN_SESSION ,

	//----------------------------------------------------------------------
	// ���̵�/�н����� ���� ����
	// Next Packets : CLGetPCList, CLLogout
	//----------------------------------------------------------------------
	LPS_WAITING_FOR_CL_GET_PC_LIST ,				

	//----------------------------------------------------------------------
	// guest �� �α׿����� ���
	// Next Packets : CLRegisterPlayer, CLQueryPlayerID
	//----------------------------------------------------------------------
	LPS_WAITING_FOR_CL_REGISTER_PLAYER,

	//----------------------------------------------------------------------
	// ĳ���� ���� ����
	// Next Packets : CLCreatePC, CLDeletePC, CLSelectPC, CLLogout
	//----------------------------------------------------------------------
	LPS_PC_MANAGEMENT ,

	//----------------------------------------------------------------------
	// ���� ������ LGIncomingConnection ��Ŷ�� ���� ����
	// Next Packets : GLIncomingConnectionOK, GLIncomingConnectionError
	//----------------------------------------------------------------------
	LPS_AFTER_SENDING_LG_INCOMING_CONNECTION ,

	//----------------------------------------------------------------------
	// '�̹� ���� ��'�� ���..
	// ���� ���� ���ᰡ �Ǳ⸦ ��ٸ��� ����
	//----------------------------------------------------------------------
	LPS_WAITING_FOR_GL_KICK_VERIFY,


	//----------------------------------------------------------------------
	// �α��� �������� ������ �����Ҷ�
	// Next Packets : NONE
	//----------------------------------------------------------------------
	LPS_END_SESSION ,


	/*
	//----------------------------------------------------------------------
	// ���� �Խ��� ����
	//----------------------------------------------------------------------
	
	//----------------------------------------------------------------------
	// LPS_WAITHING_FOR_CL_SELECT_BOARD
	//----------------------------------------------------------------------
	 LPS_WAITING_FOR_CL_SELECT_BOARD,

	//----------------------------------------------------------------------
	// LPS_AFTER_SENDING_CL_TEXT_LIST
	//----------------------------------------------------------------------
	 LPS_AFTER_SENDING_LC_TEXT_LIST,
		    
	//----------------------------------------------------------------------
	// LPS_AFTER_SENDING_CL_SENDING_CONTENT
	//----------------------------------------------------------------------
	 LPS_AFTER_SENDING_LC_SEND_CONTENT,
	
	//----------------------------------------------------------------------
	// ���� �Խ��� ���
	//----------------------------------------------------------------------
	*/
	
#elif defined(__GAME_SERVER__)

	//----------------------------------------------------------------------
	// GamePlayer ��ü�� ������ ����
	// Next Packets : NONE
	//----------------------------------------------------------------------
	GPS_NONE ,

	//----------------------------------------------------------------------
	// ���� ������ ���� ���� ����
	// Next Packets : CGConnect
	//----------------------------------------------------------------------
	GPS_BEGIN_SESSION ,

	//----------------------------------------------------------------------
	// ����� ���� ���� 
	// Next Packets : CGReady
	//----------------------------------------------------------------------
	GPS_WAITING_FOR_CG_READY ,

	//----------------------------------------------------------------------
	// ���ӿ� ����. ���� �ƹ� ��Ŷ�̳� �Ͷ�.
	// Next Packets : ANY
	//----------------------------------------------------------------------
	GPS_NORMAL,

	//----------------------------------------------------------------------
	// �ƹ� ��Ŷ�� ���� �ʴ� ���´�. -_-; fuck suck
	//----------------------------------------------------------------------
	GPS_IGNORE_ALL,

	//----------------------------------------------------------------------
	// �α��� ������ GLIncomingConnection ��Ŷ�� ���� ����
	// Next Packets : LGIncomingConnectionOK, LGIncomingConnectionError
	//----------------------------------------------------------------------
	GPS_AFTER_SENDING_GL_INCOMING_CONNECTION ,

	//----------------------------------------------------------------------
	// ���� �������� ������ �����Ѵ�.
	// Next Packets : NONE
	//----------------------------------------------------------------------
	GPS_END_SESSION ,


#elif defined(__UPDATE_SERVER__)

	//----------------------------------------------------------------------
	// UpdateServerPlayer ��ü�� ������ ����
	// Next Packets : NONE
	//----------------------------------------------------------------------
	USPS_NONE,

	//----------------------------------------------------------------------
	// ������Ʈ Ŭ���̾�Ʈ�� ������ �� ����
	// Next Packets : CUBeginUpdate
	//----------------------------------------------------------------------
	USPS_BEGIN_SESSION,

	//----------------------------------------------------------------------
	// UCUpdateList �� ���� ����
	// Next Packets : CURequest, CUEndUpdate
	//----------------------------------------------------------------------
	USPS_AFTER_SENDING_UC_UPDATE_LIST,

	//----------------------------------------------------------------------
	// UCUpdate �� ���� ����
	// Next Packets : CURequest, CUEndUpdate
	//----------------------------------------------------------------------
	USPS_AFTER_SENDING_UC_UPDATE,

	//----------------------------------------------------------------------
	// CUEndUpdate �� ���� ����
	// Next Packets : NONE
	//----------------------------------------------------------------------
	USPS_END_SESSION,

#elif defined(__UPDATE_CLIENT__)

	//----------------------------------------------------------------------
	// UpdateClientPlayer ��ü�� ������ ����
	// Next Packets : NONE
	//----------------------------------------------------------------------
	UCPS_NONE ,
	
	//----------------------------------------------------------------------
	// ������Ʈ ������ ������ ����
	// Next Packets : NONE
	//----------------------------------------------------------------------
	UCPS_BEGIN_SESSION,

	//----------------------------------------------------------------------
	// CUBeginUpdate ��Ŷ�� ���� ����
	// Next Packets : UCUpdateList
	//----------------------------------------------------------------------
	UCPS_WAITING_FOR_UC_UPDATE_LIST,

	//----------------------------------------------------------------------
	// CURequest ��Ŷ�� ���� ����
	// Next Packets : UCUpdate
	//----------------------------------------------------------------------
	UCPS_WAITING_FOR_UC_UPDATE,

	//----------------------------------------------------------------------
	// ������Ʈ �������� ������ �����Ѵ�.
	// Next Packets : NONE
	//----------------------------------------------------------------------
	UCPS_END_SESSION,

#endif

	//--------------------------------------------------
	// Player Status �迭�� ũ�� ���� ������ �� ���ȴ�.
	//--------------------------------------------------
	PLAYER_STATUS_MAX

};

#endif