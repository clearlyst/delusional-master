#pragma once
#include "../math/vec3.hpp"
#include "../sdk.hpp"
#include <minwindef.h>

class player_t;
#define	SURF_LIGHT		0x0001		// value will hold the light strength
#define	SURF_SKY2D		0x0002		// don't draw, indicates we should skylight + draw 2d sky but not draw the 3D skybox
#define	SURF_SKY		0x0004		// don't draw, but add to skybox
#define	SURF_WARP		0x0008		// turbulent water warp
#define	SURF_TRANS		0x0010
#define SURF_NOPORTAL	0x0020	// the surface can not have a portal placed on it
#define	SURF_TRIGGER	0x0040	// FIXME: This is an xbox hack to work around elimination of trigger surfaces, which breaks occluders
#define	SURF_NODRAW		0x0080	// don't bother referencing the texture
#define	SURF_HINT		0x0100	// make a primary bsp splitter
#define	SURF_SKIP		0x0200	// completely ignore, allowing non-closed brushes
#define SURF_NOLIGHT	0x0400	// Don't calculate light
#define SURF_BUMPLIGHT	0x0800	// calculate three lightmaps for the surface for bumpmapping
#define SURF_NOSHADOWS	0x1000	// Don't receive shadows
#define SURF_NODECALS	0x2000	// Don't receive decals
#define SURF_NOPAINT	0x2000	// the surface can not have paint placed on it
#define SURF_NOCHOP		0x4000	// Don't subdivide patches on this surface
#define SURF_HITBOX		0x8000	// surface is part of a hitbox

#define CHAR_TEX_ANTLION		'A'
#define CHAR_TEX_BLOODYFLESH	'B'
#define	CHAR_TEX_CONCRETE		'C'
#define CHAR_TEX_DIRT			'D'
#define CHAR_TEX_EGGSHELL		'E' ///< the egg sacs in the tunnels in ep2.
#define CHAR_TEX_FLESH			'F'
#define CHAR_TEX_GRATE			'G'
#define CHAR_TEX_ALIENFLESH		'H'
#define CHAR_TEX_CLIP			'I'
//#define CHAR_TEX_UNUSED		'J'
#define CHAR_TEX_SNOW			'K'
#define CHAR_TEX_PLASTIC		'L'
#define CHAR_TEX_METAL			'M'
#define CHAR_TEX_SAND			'N'
#define CHAR_TEX_FOLIAGE		'O'
#define CHAR_TEX_COMPUTER		'P'
//#define CHAR_TEX_UNUSED		'Q'
#define CHAR_TEX_REFLECTIVE		'R'
#define CHAR_TEX_SLOSH			'S'
#define CHAR_TEX_TILE			'T'
#define CHAR_TEX_CARDBOARD		'U'
#define CHAR_TEX_VENT			'V'
#define CHAR_TEX_WOOD			'W'
//#define CHAR_TEX_UNUSED		'X' ///< do not use - "fake" materials use this (ladders, wading, clips, etc)
#define CHAR_TEX_GLASS			'Y'
#define CHAR_TEX_WARPSHIELD		'Z' ///< wierd-looking jello effect for advisor shield.

#define	CONTENTS_EMPTY			0		/**< No contents. */
#define	CONTENTS_SOLID			0x1		/**< an eye is never valid in a solid . */
#define	CONTENTS_WINDOW			0x2		/**< translucent, but not watery (glass). */
#define	CONTENTS_AUX			0x4
#define	CONTENTS_GRATE			0x8		/**< alpha-tested "grate" textures.  Bullets/sight pass through, but solids don't. */
#define	CONTENTS_SLIME			0x10
#define	CONTENTS_WATER			0x20
#define	CONTENTS_MIST			0x40
#define CONTENTS_OPAQUE			0x80		/**< things that cannot be seen through (may be non-solid though). */
#define	LAST_VISIBLE_CONTENTS	0x80
#define ALL_VISIBLE_CONTENTS 	(LAST_VISIBLE_CONTENTS | (LAST_VISIBLE_CONTENTS-1))
#define CONTENTS_TESTFOGVOLUME	0x100
#define CONTENTS_UNUSED5		0x200
#define CONTENTS_UNUSED6		0x4000
#define CONTENTS_TEAM1			0x800		/**< per team contents used to differentiate collisions. */
#define CONTENTS_TEAM2			0x1000		/**< between players and objects on different teams. */
#define CONTENTS_IGNORE_NODRAW_OPAQUE	0x2000		/**< ignore CONTENTS_OPAQUE on surfaces that have SURF_NODRAW. */
#define CONTENTS_MOVEABLE		0x4000		/**< hits entities which are MOVETYPE_PUSH (doors, plats, etc) */
#define	CONTENTS_AREAPORTAL		0x8000		/**< remaining contents are non-visible, and don't eat brushes. */
#define	CONTENTS_PLAYERCLIP		0x10000
#define	CONTENTS_MONSTERCLIP	0x20000

/**
* @section currents can be added to any other contents, and may be mixed
*/
#define	CONTENTS_CURRENT_0		0x40000
#define	CONTENTS_CURRENT_90		0x80000
#define	CONTENTS_CURRENT_180	0x100000
#define	CONTENTS_CURRENT_270	0x200000
#define	CONTENTS_CURRENT_UP		0x400000
#define	CONTENTS_CURRENT_DOWN	0x800000

/**
* @endsection
*/

#define	CONTENTS_ORIGIN			0x1000000	/**< removed before bsping an entity. */
#define	CONTENTS_MONSTER		0x2000000	/**< should never be on a brush, only in game. */
#define	CONTENTS_DEBRIS			0x4000000
#define	CONTENTS_DETAIL			0x8000000	/**< brushes to be added after vis leafs. */
#define	CONTENTS_TRANSLUCENT	0x10000000	/**< auto set if any surface has trans. */
#define	CONTENTS_LADDER			0x20000000
#define CONTENTS_HITBOX			0x40000000	/**< use accurate hitboxes on trace. */

/**
* @section Trace masks.
*/
#define	MASK_ALL				(0xFFFFFFFF)
#define	MASK_SOLID				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE) 			/**< everything that is normally solid */
#define	MASK_PLAYERSOLID		(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_PLAYERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE) 	/**< everything that blocks player movement */
#define	MASK_NPCSOLID			(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE) /**< blocks npc movement */
#define	MASK_WATER				(CONTENTS_WATER|CONTENTS_MOVEABLE|CONTENTS_SLIME) 							/**< water physics in these contents */
#define	MASK_OPAQUE				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_OPAQUE) 							/**< everything that blocks line of sight for AI, lighting, etc */
#define MASK_OPAQUE_AND_NPCS	(MASK_OPAQUE|CONTENTS_MONSTER)										/**< everything that blocks line of sight for AI, lighting, etc, but with monsters added. */
#define	MASK_VISIBLE			(MASK_OPAQUE|CONTENTS_IGNORE_NODRAW_OPAQUE) 								/**< everything that blocks line of sight for players */
#define MASK_VISIBLE_AND_NPCS	(MASK_OPAQUE_AND_NPCS|CONTENTS_IGNORE_NODRAW_OPAQUE) 							/**< everything that blocks line of sight for players, but with monsters added. */
#define	MASK_SHOT				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_HITBOX) 	/**< bullets see these as solid */
#define MASK_SHOT_HULL			(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_GRATE) 	/**< non-raycasted weapons see this as solid (includes grates) */
#define MASK_SHOT_PORTAL		(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW) 							/**< hits solids (not grates) and passes through everything else */
#define MASK_SOLID_BRUSHONLY	(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_GRATE) 					/**< everything normally solid, except monsters (world+brush only) */
#define MASK_PLAYERSOLID_BRUSHONLY	(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_PLAYERCLIP|CONTENTS_GRATE) 			/**< everything normally solid for player movement, except monsters (world+brush only) */
#define MASK_NPCSOLID_BRUSHONLY	(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE) 			/**< everything normally solid for npc movement, except monsters (world+brush only) */
#define MASK_NPCWORLDSTATIC		(CONTENTS_SOLID|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE) 					/**< just the world, used for route rebuilding */
#define MASK_SPLITAREAPORTAL	(CONTENTS_WATER|CONTENTS_SLIME) 									/**< These are things that can split areaportals */

enum trace_type {
	e_trace_everything = 0,
	e_trace_world_only,
	e_trace_entities_only,
	e_trace_everything_filter_props,
	e_trace_filtersky
};

class i_handle_entity;

struct ray_t {
	vector_aligned		m_start;
	vector_aligned		m_delta;
	vector_aligned		m_start_offset;
	vector_aligned		m_extents;
	const matrix_t* m_world_axis_transform;
	bool				m_is_ray;
	bool				m_is_swept;

	void initialize(const vec3_t& start, const vec3_t& end) {
		m_delta = end - start;

		m_is_swept = (m_delta.length_sqr() != 0);

		m_extents.x = m_extents.y = m_extents.z = 0.0f;
		m_is_ray = true;

		m_start_offset.x = m_start_offset.y = m_start_offset.z = 0.0f;

		m_start = start;
	}

	void initialize(vec3_t const& vecStart, vec3_t const& vecEnd, vec3_t const& min, vec3_t const& max) {
		m_delta = vecEnd - vecStart;

		m_world_axis_transform = NULL;
		m_is_swept = (m_delta.length_sqr() != 0);

		m_extents = max - min;
		m_extents *= 0.5f;
		m_is_ray = (m_extents.length_sqr() < 1e-6);

		m_start_offset = max + min;
		m_start_offset *= 0.5f;
		m_start = vecStart + m_start_offset;
		m_start_offset *= -1.0f;
	}

private:
};

struct csurface_t {
	const char* name;
	short surfaceProps;
	std::uint16_t flags;
};

struct cplane_t {
	constexpr auto operator!=(const cplane_t& v) const {
		return normal.x != v.normal.x || normal.y != v.normal.y || normal.z != v.normal.z;
	}

	vec3_t normal;
	float m_dist;
	std::byte	type;
	std::byte	sign_bits;
	std::byte	pad[0x2];
};

struct trace_t {
	vec3_t start;
	vec3_t end;
	cplane_t plane;
	float flFraction;
	int contents;
	std::uint16_t dispFlags;
	bool allsolid;
	bool startSolid;
	float fractionLeftSolid;
	csurface_t surface;
	int hit_group;
	short physicsBone;
	std::uint16_t worldSurfaceIndex;
	player_t* entity;
	int hitbox;

	bool did_hit() const {
		return flFraction < 1.f;
	}

	bool did_hit_world() const {
		return false;
	}

	bool did_hit_non_world_entity() const {
		return entity != NULL && !did_hit_world();
	}
};


class i_trace_filter {
public:
	virtual bool should_hit_entity(void* p_entity, int contentsMask) = 0;
	virtual trace_type get_trace_type() const = 0;
};

class trace_filter : public i_trace_filter {
public:
	bool should_hit_entity(void* pEntityHandle, int contentsMask) {
		return (pEntityHandle != skip);
	}

	trace_type get_trace_type() const {
		return e_trace_everything;
	}

	trace_filter() {};
	trace_filter(player_t* ent) {
		this->skip = ent;
	}

	const void* skip;
};

class trace_filter_one_entity : public i_trace_filter {
public:
	bool should_hit_entity(void* pEntityHandle, int contentsMask) {
		return (pEntityHandle == p_entity);
	}

	trace_type get_trace_type() const {
		return e_trace_everything;
	}

	void* p_entity;
};

class trace_filter_one_entity2 : public i_trace_filter {
public:
	bool should_hit_entity(void* pEntityHandle, int contentsMask) {
		return (pEntityHandle == p_entity);
	}

	trace_type get_trace_type() const {
		return e_trace_entities_only;
	}

	void* p_entity;
};

class trace_filter_skip_two_entities : public i_trace_filter {
public:
	trace_filter_skip_two_entities(void* pPassEnt1, void* pPassEnt2) {
		passentity1 = pPassEnt1;
		passentity2 = pPassEnt2;
	}

	virtual bool should_hit_entity(void* pEntityHandle, int contentsMask) {
		return !(pEntityHandle == passentity1 || pEntityHandle == passentity2);
	}

	virtual trace_type get_trace_type() const {
		return e_trace_everything;
	}

	void* passentity1;
	void* passentity2;
};

class trace_filter_skip_one_entity : public i_trace_filter {
public:
	trace_filter_skip_one_entity(void* pPassEnt1) {
		passentity1 = pPassEnt1;
	}

	virtual bool should_hit_entity(void* pEntityHandle, int contentsMask) {
		return !(pEntityHandle == passentity1);
	}

	virtual trace_type get_trace_type() const {
		return e_trace_everything;
	}

	void* passentity1;
};

class trace_entity : public i_trace_filter {
public:
	bool should_hit_entity(void* pEntityHandle, int contentsMask) {
		return !(pEntityHandle == p_skip1);
	}

	trace_type get_trace_type() const {
		return e_trace_entities_only;
	}

	void* p_skip1;
};

class trace_world_only : public i_trace_filter {
public:
	bool should_hit_entity(void* pEntityHandle, int contentsMask) {
		return false;
	}

	trace_type get_trace_type() const {
		return e_trace_everything;
	}

	void* p_skip1;
};

class collideable_t;

class trace {
public:
	virtual int get_point_contents(const vec3_t& abs_position, int contents_mask = MASK_ALL, i_handle_entity** entity = nullptr) = 0;
	virtual int get_point_contents_world_only(const vec3_t& abs_position, int contents_mask = MASK_ALL) = 0;
	virtual int get_point_contents_collideable(collideable_t* collide, const vec3_t& abs_position) = 0;
	virtual void clip_ray_to_entity(const ray_t& ray, unsigned int mask, i_handle_entity* entity, trace_t* trace) = 0;
	virtual void clip_ray_to_collideable(const ray_t& ray, unsigned int mask, collideable_t* pCollide, trace_t* trace) = 0;
	virtual void trace_ray(const ray_t& ray, unsigned int mask, i_trace_filter* filter, trace_t* trace) = 0;
	virtual void sweep_collideable(collideable_t* collide, const vec3_t& abs_start, const vec3_t& abs_end, const vec3_t& angles, unsigned int mask, i_trace_filter* trace_filter, trace_t* trace) = 0;
	virtual collideable_t* get_collideable(i_handle_entity* entity) = 0;
	virtual int get_stat_by_index(int index, bool clear) = 0;
	virtual void get_brushes_in_aabb(const vec3_t& mins, const vec3_t& maxs,CUtlVector<int>* output, int contents_mask = MASK_ALL) = 0;
	virtual int get_num_displacements() = 0;
	virtual bool point_outside_world(const vec3_t& point) = 0;
	virtual int get_leaf_containing_point(const vec3_t& point) = 0;
	virtual void suspend_occlusion_tests() = 0;
	virtual void resume_occlusion_tests() = 0;
	virtual void flush_occlusion_queries() = 0;
};
