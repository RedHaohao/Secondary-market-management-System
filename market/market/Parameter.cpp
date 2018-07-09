#include "Parameter.h"

Parameter * Parameter::m_Parameter = NULL;

Parameter::Parameter()
{
}


Parameter::~Parameter()
{
}

Parameter *Parameter::getInstance()
{
	if (m_Parameter == NULL)
	{
		m_Parameter = new Parameter();
	}
	return m_Parameter;
}

void Parameter::initParameter(){
	m_vUserID = -1;
}
