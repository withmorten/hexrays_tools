#pragma once
extern void convert_negative_offset_casts(cfunc_t *cfunc);

extern bool can_be_recast(void * ud);
extern bool idaapi change_negative_cast_callback(void *ud);

extern void set_cache_dirty();
extern bool fill_graphreferences();



struct struc_backreference_t
{
	uval_t idx;
	int offset;
	DECLARE_COMPARISONS(struc_backreference_t)
	{
	
		if (idx < r.idx)
			return -1;

		if (idx > r.idx)
			return 1;

		if (idx == r.idx)
			return 0;

		if (offset < r.offset)
			return -1;

		if (offset > r.offset)
			return 1;

		return -2;
	};
};

enum struc_reference_type_t
{
	srt_invalid=-1,
	srt_substruct=1,
	srt_struct_reference=2,
	srt_type_reference=4,
};

struct struc_reference_t
{
	uval_t idx_from;
	uval_t idx_to;
	struc_reference_type_t type;

	struc_reference_t::struc_reference_t():idx_from(BADNODE), idx_to(BADNODE), type(srt_invalid)
	{}

	DECLARE_COMPARISONS(struc_reference_t)
	{	
		if (idx_from < r.idx_from)
			return -1;

		if (idx_from > r.idx_from)
			return 1;		

		if (idx_to < r.idx_to)
			return -1;

		if (idx_to > r.idx_to)
			return 1;

		if (type < r.type)
			return -1;

		if (type > r.type)
			return 1;

		if (type == r.type)
			return 0;

		return -2;
	};
};

typedef qvector<struc_backreference_t>  sbrvec_t;
typedef qvector<sbrvec_t> sbrvecvec_t;
typedef qvector<struc_reference_t> srvec_t;


extern srvec_t graph_references;
extern intvec_t nonempty;
extern intvec_t nonempty_back;
extern int nonempty_cnt;