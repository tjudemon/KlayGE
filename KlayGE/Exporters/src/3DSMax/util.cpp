// util.cpp
// KlayGE 实用函数 实现文件
// Ver 2.5.0
// 版权所有(C) 龚敏敏, 2005
// Homepage: http://www.klayge.org
//
// 2.5.0
// 初次建立 (2005.5.1)
//
// 修改记录
/////////////////////////////////////////////////////////////////////////////////

#pragma warning(push)
#pragma warning(disable: 4100 4238 4239 4244 4245 4512)
#include <max.h>
#if VERSION_3DSMAX >= 7 << 16
#include <CS/bipexp.h>
#else
#include <bipexp.h>
#endif
#pragma warning(pop)

#ifdef UNICODE
#include <vector>
#endif
#include "util.hpp"

namespace KlayGE
{
	std::string tstr_to_str(std::basic_string<TCHAR> const & tstr)
	{
	#ifdef UNICODE
		int const mbs_len = WideCharToMultiByte(CP_ACP, 0, tstr.c_str(), static_cast<int>(tstr.size()), NULL, 0, NULL, NULL);
		std::vector<char> tmp(mbs_len + 1);
		WideCharToMultiByte(CP_ACP, 0, tstr.c_str(), static_cast<int>(tstr.size()), &tmp[0], mbs_len, NULL, NULL);
		return std::string(tmp.begin(), tmp.end() - 1);
	#else
		return tstr;
	#endif
	}

	bool is_mesh(INode* node)
	{
		if (NULL == node)
		{
			return false;
		}

		ObjectState os = node->EvalWorldState(0);
		if (NULL == os.obj)
		{
			return false;
		}

		if (os.obj->SuperClassID() == GEOMOBJECT_CLASS_ID)
		{
			if (os.obj->ClassID() != Class_ID(TARGET_CLASS_ID, 0))
			{
				return true;
			}
		}
		
		return false;
	}

	bool is_bone(INode* node)
	{
		if (NULL == node)
		{
			return false;
		}

		ObjectState os = node->EvalWorldState(0);
		if (NULL == os.obj)
		{
			return false;
		}

		if (os.obj->SuperClassID() == HELPER_CLASS_ID)
		{
			return true;
		}

		if (os.obj->SuperClassID() == GEOMOBJECT_CLASS_ID)
		{
			if (os.obj->ClassID() == BONE_OBJ_CLASSID)
			{
				return true;
			}
		}

		Control* ctl = node->GetTMController();
		if ((ctl->ClassID() == BIPSLAVE_CONTROL_CLASS_ID)
			|| (ctl->ClassID() == BIPBODY_CONTROL_CLASS_ID))
		{
			return true;
		}

		return false;
	}
}
