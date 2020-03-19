
// Include
#include "messagingcomponent.h"

#include "blaze/client.h"
#include "blaze/functions.h"
#include "utils/functions.h"

#include <iostream>

/*
	Packet IDs
		0x01 = SendMessage
		0x02 = FetchMessages
		0x03 = PurgeMessages
		0x04 = TouchMessages
		0x05 = GetMessages

	Notification Packet IDs
		0x01 = NotifyMessage

	Blaze fields
		ServerMessage (NotifyMessage)
			FLAG = 0x28
			MGID = 0x38
			NAME = 0x24
			PYLD = 0x18
			SRCE = 0x08
			TIME = 0x38


	Message types
		0-2 = user message types
		2 = playgroup, lobby & game message types

		static var kMessageType_Tell = 0;
		static var kMessageType_Party = 7;
		static var kMessageType_Game = 8;
		static var kMessageType_Lobby = 9;
		static var kMessageType_System = 14;
		static var kMessageType_Warning = 15;
		static var kMessageType_SporeNetBroadcast = 16;
*/

// Blaze
namespace Blaze {
	// MessagingComponent
	void MessagingComponent::Parse(Client* client, const Header& header) {
		switch (header.command) {
			case 0x01:
				OnSendMessage(client, header);
				break;

			case 0x02:
				OnFetchMessages(client, header);
				break;

			case 0x03:
				OnPurgeMessages(client, header);
				break;

			case 0x04:
				OnTouchMessages(client, header);
				break;

			case 0x05:
				OnGetMessages(client, header);
				break;

			default:
				std::cout << "Unknown messaging command: 0x" << std::hex << header.command << std::dec << std::endl;
				break;
		}
	}

	void MessagingComponent::OnSendMessageResponse(Client* client) {
		ClientMessage message;
		message.Read(client->get_request());

		uint32_t id;
		if (!message.attributes.empty()) {
			id = message.attributes.begin()->first;
		} else {
			id = 0;
		}

		TDF::Packet packet;
		packet.put_integer("MGID", id);
		packet.push_list("MIDS", TDF::Type::Integer); // vector<uint32_t>
		for (const auto& [id, _] : message.attributes) {
			packet.put_integer("", id);
		}
		packet.pop();

		NotifyMessage(client);

		client->reply({
			.component = Component::Messaging,
			.command = 0x01
		}, packet);
	}

	void MessagingComponent::NotifyMessage(Client* client) {
		ServerMessage serverMessage;
		serverMessage.flags = 0;
		serverMessage.messageId = 1;
		serverMessage.name = "Unknown";
		serverMessage.time = static_cast<uint32_t>(utils::get_unix_time());
		
		ClientMessage& clientMessage = serverMessage.message;
		clientMessage.attributes.emplace(1, "testing 123");

		TDF::Packet packet;
		serverMessage.Write(packet);

		client->notify({
			.component = Component::Messaging,
			.command = 0x01
		}, packet);
	}

	void MessagingComponent::OnSendMessage(Client* client, Header header) {
		std::cout << "OnSendMessage" << std::endl;
		OnSendMessageResponse(client);
	}

	void MessagingComponent::OnFetchMessages(Client* client, Header header) {
		std::cout << "OnFetchMessages" << std::endl;
	}

	void MessagingComponent::OnPurgeMessages(Client* client, Header header) {
		std::cout << "OnPurgeMessages" << std::endl;
	}

	void MessagingComponent::OnTouchMessages(Client* client, Header header) {
		std::cout << "OnTouchMessages" << std::endl;
	}

	void MessagingComponent::OnGetMessages(Client* client, Header header) {
		std::cout << "OnGetMessages" << std::endl;
	}
}
