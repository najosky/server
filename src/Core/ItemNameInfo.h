//--------------------------------------------------------------------------------
// 
// Filename    : ItemNameInfo.h 
// Written By  : 
// Description : 
// 
//--------------------------------------------------------------------------------

#ifndef __ITEM_NAME_H__
#define __ITEM_NAME_H__

// include files
#include "Types.h"
#include "Packet.h"
#include "PacketFactory.h"

#include "Exception.h"

//--------------------------------------------------------------------------------
//
// class ItemNameInfo;
//
//--------------------------------------------------------------------------------

class ItemNameInfo {

public :
	ItemNameInfo() {}
	ItemNameInfo(ObjectID_t objectID, string name)
	{
		m_ObjectID = objectID;
		m_Name = name;
	}
	virtual ~ItemNameInfo() {}
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    virtual void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    virtual void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	virtual PacketSize_t getSize() const throw();

	static PacketSize_t getMaxSize() throw()
	{
		return (szObjectID + szBYTE + (szBYTE * 20));
	}

	// get packet's debug string
	string toString() const throw();

public:
	void setObjectID(ObjectID_t objectID ) throw(Error) { m_ObjectID = objectID; }
	ObjectID_t getObjectID() const throw(Error) { return m_ObjectID; }

	void setName(string name ) throw(Error) { m_Name = name; }
	string getName() const throw(Error) { return m_Name; }

protected :
	ObjectID_t		m_ObjectID;
	string			m_Name;
};

#endif