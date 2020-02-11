
#ifndef _GAME_PART_HEADER
#define _GAME_PART_HEADER

// Include
#include "game.h"

#include <map>
#include "../utils/functions.h"

// Game
namespace Game {
	// Part
	class Part {
	public:
		uint64_t id;
		uint16_t rigblock_asset_id;
		
		uint64_t timestamp;

		uint32_t rigblock_asset_hash;
		uint32_t prefix_asset_hash;
		uint32_t prefix_secondary_asset_hash;
		uint32_t suffix_asset_hash;
		uint32_t cost;
		uint32_t equipped_to_creature_id;

		uint16_t prefix_asset_id;
		uint16_t prefix_secondary_asset_id;
		uint16_t suffix_asset_id;
		uint16_t level;

		uint8_t rarity;
		uint8_t market_status;
		uint8_t status;
		uint8_t usage;

		bool flair;

		Part();
		Part(uint32_t rigblock);
		Part(const pugi::xml_node& node);

		bool ReadXml(const pugi::xml_node& node);
		void WriteXml(pugi::xml_node& node, uint32_t index, bool api = false) const;

		void ReadJson(rapidjson::Value& object);
		rapidjson::Value WriteJson(rapidjson::Document::AllocatorType& allocator, uint32_t index, bool api = false) const;

		void SetRigblock(uint16_t rigblock);
		void SetPrefix(uint16_t prefix, bool secondary = false);
		void SetSuffix(uint16_t suffix);

		void SetStatus(uint8_t newStatus);

	private:
		friend class Parts;
	};

	// Parts
	class Parts {
	public:
		decltype(auto) begin() { return mItems.begin(); }
		decltype(auto) begin() const { return mItems.begin(); }
		decltype(auto) end() { return mItems.end(); }
		decltype(auto) end() const { return mItems.end(); }

		auto& data() { return mItems; }
		const auto& data() const { return mItems; }

		Part* GetPartById(uint32_t id);

		void ReadXml(const pugi::xml_node& node);
		void WriteXml(pugi::xml_node& node, bool api = false) const;

		void ReadJson(rapidjson::Value& object);
		rapidjson::Value WriteJson(rapidjson::Document::AllocatorType& allocator, bool api = false) const;

		void Add(Part part);

	private:
		std::vector<Part> mItems;
	};
}

#endif
