#include "D_TREE_Matrix_Mod_P.h"

#include "C_ID_P.h"
#include "D_CONVERT_P.h"

using MMod_Param = Matrix_Mod_Param;

Tree_Matrix_Mod_P::Tree_Matrix_Mod_P(UndoManager* u_m) :
	tree{ ID::tree_matrix_mod },
	u_m{ u_m }
{
	for (int i = 0; i < 10; ++i) {
		auto init_src = i < 2 ? 17 : i == 2 ? 11 : i == 3 ? 20 : 0;
		auto init_dest = i == 0 ? 16 : i == 1 ? 21 : i == 2 ? 9 : i == 3 ? 8 : 0;
		ValueTree mod_tree{ String{ i } };
		mod_tree.setProperty(String{ (int)MMod_Param::amt }, 63, nullptr);
		mod_tree.setProperty(String{ (int)MMod_Param::dest }, init_dest, nullptr);
		mod_tree.setProperty(String{ (int)MMod_Param::src }, init_src, nullptr);
		tree.addChild(mod_tree, -1, nullptr);
	}
}

const int Tree_Matrix_Mod_P::mod_amt(const int mod) {
	if (mod > -1 && mod < 10) {
		auto mod_tree = tree.getChildWithName(String{ mod });
		return (int)mod_tree[String{ (int)MMod_Param::amt }];
	}
	return -1;
}

void Tree_Matrix_Mod_P::set_mod_amt(const int mod, const int setting) {
	if (mod > -1 && mod < 10) {
		auto mod_tree = tree.getChildWithName(String{ mod });
		auto setting_clamped = std::clamp(setting, 0, 127);
		u_m->beginNewTransaction();
		mod_tree.setProperty(String{ (int)MMod_Param::amt }, setting_clamped, u_m);
	}
}

const int Tree_Matrix_Mod_P::mod_dest(const int mod) {
	if (mod > -1 && mod < 10) {
		auto mod_tree = tree.getChildWithName(String{ mod });
		return (int)mod_tree[String{ (int)MMod_Param::dest }];
	}
	return -1;
}

void Tree_Matrix_Mod_P::set_mod_dest(const int mod, const int setting) {
	if (mod > -1 && mod < 10) {
		auto mod_tree = tree.getChildWithName(String{ mod });
		auto setting_clamped = std::clamp(setting, 0, 32);
		u_m->beginNewTransaction();
		mod_tree.setProperty(String{ (int)MMod_Param::dest }, setting_clamped, u_m);
	}
}

const int Tree_Matrix_Mod_P::mod_src(const int mod) {
	if (mod > -1 && mod < 10) {
		auto mod_tree = tree.getChildWithName(String{ mod });
		return (int)mod_tree[String{ (int)MMod_Param::src }];
	}
	return -1;
}

void Tree_Matrix_Mod_P::set_mod_src(const int mod, const int setting) {
	if (mod > -1 && mod < 10) {
		auto mod_tree = tree.getChildWithName(String{ mod });
		auto setting_clamped = std::clamp(setting, 0, 20);
		u_m->beginNewTransaction();
		mod_tree.setProperty(String{ (int)MMod_Param::src }, setting_clamped, u_m);
	}
}

Value Tree_Matrix_Mod_P::get_param_as_value(const int mod, const Matrix_Mod_Param param) {
	if (mod > -1 && mod < 10) {
		auto mod_tree = tree.getChildWithName(String{ mod });
		return mod_tree.getPropertyAsValue(String{ (int)param }, u_m);
	}
	return {};
}

StringArray Tree_Matrix_Mod_P::choices_list_for(const Matrix_Mod_Param param, const bool curt) {
	StringArray list{};
	switch (param)
	{
	case Matrix_Mod_Param::amt:
		for (int i = 0; i < 128; ++i)
			list.add(Convert_P::int_to_mmod_amt(i, curt));
		break;
	case Matrix_Mod_Param::dest:
		for (int i = 0; i < 33; ++i)
			list.add(Convert_P::int_to_mmod_dest(i, curt));
		break;
	case Matrix_Mod_Param::src:
		for (int i = 0; i < 21; ++i)
			list.add(Convert_P::int_to_mmod_src(i, curt));
		break;
	default:
		break;
	}
	return list;
}

std::unique_ptr<XmlElement> Tree_Matrix_Mod_P::get_state() {
	auto state{ tree.createXml() };
	if (state)
		state->setTagName(ID::xml_state_matrix_mod);
	return state;
}

void Tree_Matrix_Mod_P::replace_state(const ValueTree& new_state) {
	if (new_state.isValid())
		tree.copyPropertiesAndChildrenFrom(new_state, nullptr);
}
