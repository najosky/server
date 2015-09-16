//////////////////////////////////////////////////////////////////////
// 
// Filename    : GCSelectRankBonusFailed.cc 
// Written By  : elca@ewestsoft.com
// Description : Skill�� ���� ������ �����ִ� ��Ŷ�� ��� ����
// 
//////////////////////////////////////////////////////////////////////

// include files
#include "GCSelectRankBonusFailed.h"



//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
GCSelectRankBonusFailed::GCSelectRankBonusFailed() 
	throw()
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
GCSelectRankBonusFailed::~GCSelectRankBonusFailed() 
	throw()
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
// �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
//////////////////////////////////////////////////////////////////////
void GCSelectRankBonusFailed::read (SocketInputStream & iStream ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY

	iStream.read(m_RankBonusType);
	iStream.read(m_Desc);

	__END_CATCH
}

		    
//////////////////////////////////////////////////////////////////////
// ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
//////////////////////////////////////////////////////////////////////
void GCSelectRankBonusFailed::write (SocketOutputStream & oStream ) const 
     throw(ProtocolException , Error )
{
	__BEGIN_TRY

	oStream.write(m_RankBonusType);
	oStream.write(m_Desc);

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// execute packet's handler
//////////////////////////////////////////////////////////////////////
void GCSelectRankBonusFailed::execute (Player * pPlayer ) 
	 throw(ProtocolException , Error )
{
	__BEGIN_TRY
		
	GCSelectRankBonusFailedHandler::execute(this , pPlayer);
		
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// get packet's debug string
//
//////////////////////////////////////////////////////////////////////
string GCSelectRankBonusFailed::toString () const
       throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "GCSelectRankBonusFailed(" 
	 		<< "RankBonusType:" << m_RankBonusType
			<< ",Desc:"      << (int)m_Desc
			<< ")" ;
	return msg.toString();

	__END_CATCH
}
