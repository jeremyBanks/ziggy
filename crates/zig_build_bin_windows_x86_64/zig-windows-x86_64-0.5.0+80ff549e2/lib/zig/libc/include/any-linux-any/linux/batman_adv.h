/* SPDX-License-Identifier: MIT */
/* Copyright (C) 2016-2018  B.A.T.M.A.N. contributors:
 *
 * Matthias Schiffer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef _LINUX_BATMAN_ADV_H_
#define _LINUX_BATMAN_ADV_H_

#define BATADV_NL_NAME "batadv"

#define BATADV_NL_MCAST_GROUP_TPMETER	"tpmeter"

/**
 * enum batadv_tt_client_flags - TT client specific flags
 *
 * Bits from 0 to 7 are called _remote flags_ because they are sent on the wire.
 * Bits from 8 to 15 are called _local flags_ because they are used for local
 * computations only.
 *
 * Bits from 4 to 7 - a subset of remote flags - are ensured to be in sync with
 * the other nodes in the network. To achieve this goal these flags are included
 * in the TT CRC computation.
 */
enum batadv_tt_client_flags {
	/**
	 * @BATADV_TT_CLIENT_DEL: the client has to be deleted from the table
	 */
	BATADV_TT_CLIENT_DEL     = (1 << 0),

	/**
	 * @BATADV_TT_CLIENT_ROAM: the client roamed to/from another node and
	 * the new update telling its new real location has not been
	 * received/sent yet
	 */
	BATADV_TT_CLIENT_ROAM    = (1 << 1),

	/**
	 * @BATADV_TT_CLIENT_WIFI: this client is connected through a wifi
	 * interface. This information is used by the "AP Isolation" feature
	 */
	BATADV_TT_CLIENT_WIFI    = (1 << 4),

	/**
	 * @BATADV_TT_CLIENT_ISOLA: this client is considered "isolated". This
	 * information is used by the Extended Isolation feature
	 */
	BATADV_TT_CLIENT_ISOLA	 = (1 << 5),

	/**
	 * @BATADV_TT_CLIENT_NOPURGE: this client should never be removed from
	 * the table
	 */
	BATADV_TT_CLIENT_NOPURGE = (1 << 8),

	/**
	 * @BATADV_TT_CLIENT_NEW: this client has been added to the local table
	 * but has not been announced yet
	 */
	BATADV_TT_CLIENT_NEW     = (1 << 9),

	/**
	 * @BATADV_TT_CLIENT_PENDING: this client is marked for removal but it
	 * is kept in the table for one more originator interval for consistency
	 * purposes
	 */
	BATADV_TT_CLIENT_PENDING = (1 << 10),

	/**
	 * @BATADV_TT_CLIENT_TEMP: this global client has been detected to be
	 * part of the network but no nnode has already announced it
	 */
	BATADV_TT_CLIENT_TEMP	 = (1 << 11),
};

/**
 * enum batadv_mcast_flags_priv - Private, own multicast flags
 *
 * These are internal, multicast related flags. Currently they describe certain
 * multicast related attributes of the segment this originator bridges into the
 * mesh.
 *
 * Those attributes are used to determine the public multicast flags this
 * originator is going to announce via TT.
 *
 * For netlink, if BATADV_MCAST_FLAGS_BRIDGED is unset then all querier
 * related flags are undefined.
 */
enum batadv_mcast_flags_priv {
	/**
	 * @BATADV_MCAST_FLAGS_BRIDGED: There is a bridge on top of the mesh
	 * interface.
	 */
	BATADV_MCAST_FLAGS_BRIDGED			= (1 << 0),

	/**
	 * @BATADV_MCAST_FLAGS_QUERIER_IPV4_EXISTS: Whether an IGMP querier
	 * exists in the mesh
	 */
	BATADV_MCAST_FLAGS_QUERIER_IPV4_EXISTS		= (1 << 1),

	/**
	 * @BATADV_MCAST_FLAGS_QUERIER_IPV6_EXISTS: Whether an MLD querier
	 * exists in the mesh
	 */
	BATADV_MCAST_FLAGS_QUERIER_IPV6_EXISTS		= (1 << 2),

	/**
	 * @BATADV_MCAST_FLAGS_QUERIER_IPV4_SHADOWING: If an IGMP querier
	 * exists, whether it is potentially shadowing multicast listeners
	 * (i.e. querier is behind our own bridge segment)
	 */
	BATADV_MCAST_FLAGS_QUERIER_IPV4_SHADOWING	= (1 << 3),

	/**
	 * @BATADV_MCAST_FLAGS_QUERIER_IPV6_SHADOWING: If an MLD querier
	 * exists, whether it is potentially shadowing multicast listeners
	 * (i.e. querier is behind our own bridge segment)
	 */
	BATADV_MCAST_FLAGS_QUERIER_IPV6_SHADOWING	= (1 << 4),
};

/**
 * enum batadv_nl_attrs - batman-adv netlink attributes
 */
enum batadv_nl_attrs {
	/**
	 * @BATADV_ATTR_UNSPEC: unspecified attribute to catch errors
	 */
	BATADV_ATTR_UNSPEC,

	/**
	 * @BATADV_ATTR_VERSION: batman-adv version string
	 */
	BATADV_ATTR_VERSION,

	/**
	 * @BATADV_ATTR_ALGO_NAME: name of routing algorithm
	 */
	BATADV_ATTR_ALGO_NAME,

	/**
	 * @BATADV_ATTR_MESH_IFINDEX: index of the batman-adv interface
	 */
	BATADV_ATTR_MESH_IFINDEX,

	/**
	 * @BATADV_ATTR_MESH_IFNAME: name of the batman-adv interface
	 */
	BATADV_ATTR_MESH_IFNAME,

	/**
	 * @BATADV_ATTR_MESH_ADDRESS: mac address of the batman-adv interface
	 */
	BATADV_ATTR_MESH_ADDRESS,

	/**
	 * @BATADV_ATTR_HARD_IFINDEX: index of the non-batman-adv interface
	 */
	BATADV_ATTR_HARD_IFINDEX,

	/**
	 * @BATADV_ATTR_HARD_IFNAME: name of the non-batman-adv interface
	 */
	BATADV_ATTR_HARD_IFNAME,

	/**
	 * @BATADV_ATTR_HARD_ADDRESS: mac address of the non-batman-adv
	 * interface
	 */
	BATADV_ATTR_HARD_ADDRESS,

	/**
	 * @BATADV_ATTR_ORIG_ADDRESS: originator mac address
	 */
	BATADV_ATTR_ORIG_ADDRESS,

	/**
	 * @BATADV_ATTR_TPMETER_RESULT: result of run (see
	 * batadv_tp_meter_status)
	 */
	BATADV_ATTR_TPMETER_RESULT,

	/**
	 * @BATADV_ATTR_TPMETER_TEST_TIME: time (msec) the run took
	 */
	BATADV_ATTR_TPMETER_TEST_TIME,

	/**
	 * @BATADV_ATTR_TPMETER_BYTES: amount of acked bytes during run
	 */
	BATADV_ATTR_TPMETER_BYTES,

	/**
	 * @BATADV_ATTR_TPMETER_COOKIE: session cookie to match tp_meter session
	 */
	BATADV_ATTR_TPMETER_COOKIE,

	/**
	 * @BATADV_ATTR_PAD: attribute used for padding for 64-bit alignment
	 */
	BATADV_ATTR_PAD,

	/**
	 * @BATADV_ATTR_ACTIVE: Flag indicating if the hard interface is active
	 */
	BATADV_ATTR_ACTIVE,

	/**
	 * @BATADV_ATTR_TT_ADDRESS: Client MAC address
	 */
	BATADV_ATTR_TT_ADDRESS,

	/**
	 * @BATADV_ATTR_TT_TTVN: Translation table version
	 */
	BATADV_ATTR_TT_TTVN,

	/**
	 * @BATADV_ATTR_TT_LAST_TTVN: Previous translation table version
	 */
	BATADV_ATTR_TT_LAST_TTVN,

	/**
	 * @BATADV_ATTR_TT_CRC32: CRC32 over translation table
	 */
	BATADV_ATTR_TT_CRC32,

	/**
	 * @BATADV_ATTR_TT_VID: VLAN ID
	 */
	BATADV_ATTR_TT_VID,

	/**
	 * @BATADV_ATTR_TT_FLAGS: Translation table client flags
	 */
	BATADV_ATTR_TT_FLAGS,

	/**
	 * @BATADV_ATTR_FLAG_BEST: Flags indicating entry is the best
	 */
	BATADV_ATTR_FLAG_BEST,

	/**
	 * @BATADV_ATTR_LAST_SEEN_MSECS: Time in milliseconds since last seen
	 */
	BATADV_ATTR_LAST_SEEN_MSECS,

	/**
	 * @BATADV_ATTR_NEIGH_ADDRESS: Neighbour MAC address
	 */
	BATADV_ATTR_NEIGH_ADDRESS,

	/**
	 * @BATADV_ATTR_TQ: TQ to neighbour
	 */
	BATADV_ATTR_TQ,

	/**
	 * @BATADV_ATTR_THROUGHPUT: Estimated throughput to Neighbour
	 */
	BATADV_ATTR_THROUGHPUT,

	/**
	 * @BATADV_ATTR_BANDWIDTH_UP: Reported uplink bandwidth
	 */
	BATADV_ATTR_BANDWIDTH_UP,

	/**
	 * @BATADV_ATTR_BANDWIDTH_DOWN: Reported downlink bandwidth
	 */
	BATADV_ATTR_BANDWIDTH_DOWN,

	/**
	 * @BATADV_ATTR_ROUTER: Gateway router MAC address
	 */
	BATADV_ATTR_ROUTER,

	/**
	 * @BATADV_ATTR_BLA_OWN: Flag indicating own originator
	 */
	BATADV_ATTR_BLA_OWN,

	/**
	 * @BATADV_ATTR_BLA_ADDRESS: Bridge loop avoidance claim MAC address
	 */
	BATADV_ATTR_BLA_ADDRESS,

	/**
	 * @BATADV_ATTR_BLA_VID: BLA VLAN ID
	 */
	BATADV_ATTR_BLA_VID,

	/**
	 * @BATADV_ATTR_BLA_BACKBONE: BLA gateway originator MAC address
	 */
	BATADV_ATTR_BLA_BACKBONE,

	/**
	 * @BATADV_ATTR_BLA_CRC: BLA CRC
	 */
	BATADV_ATTR_BLA_CRC,

	/**
	 * @BATADV_ATTR_DAT_CACHE_IP4ADDRESS: Client IPv4 address
	 */
	BATADV_ATTR_DAT_CACHE_IP4ADDRESS,

	/**
	 * @BATADV_ATTR_DAT_CACHE_HWADDRESS: Client MAC address
	 */
	BATADV_ATTR_DAT_CACHE_HWADDRESS,

	/**
	 * @BATADV_ATTR_DAT_CACHE_VID: VLAN ID
	 */
	BATADV_ATTR_DAT_CACHE_VID,

	/**
	 * @BATADV_ATTR_MCAST_FLAGS: Per originator multicast flags
	 */
	BATADV_ATTR_MCAST_FLAGS,

	/**
	 * @BATADV_ATTR_MCAST_FLAGS_PRIV: Private, own multicast flags
	 */
	BATADV_ATTR_MCAST_FLAGS_PRIV,

	/* add attributes above here, update the policy in netlink.c */

	/**
	 * @__BATADV_ATTR_AFTER_LAST: internal use
	 */
	__BATADV_ATTR_AFTER_LAST,

	/**
	 * @NUM_BATADV_ATTR: total number of batadv_nl_attrs available
	 */
	NUM_BATADV_ATTR = __BATADV_ATTR_AFTER_LAST,

	/**
	 * @BATADV_ATTR_MAX: highest attribute number currently defined
	 */
	BATADV_ATTR_MAX = __BATADV_ATTR_AFTER_LAST - 1
};

/**
 * enum batadv_nl_commands - supported batman-adv netlink commands
 */
enum batadv_nl_commands {
	/**
	 * @BATADV_CMD_UNSPEC: unspecified command to catch errors
	 */
	BATADV_CMD_UNSPEC,

	/**
	 * @BATADV_CMD_GET_MESH_INFO: Query basic information about batman-adv
	 * device
	 */
	BATADV_CMD_GET_MESH_INFO,

	/**
	 * @BATADV_CMD_TP_METER: Start a tp meter session
	 */
	BATADV_CMD_TP_METER,

	/**
	 * @BATADV_CMD_TP_METER_CANCEL: Cancel a tp meter session
	 */
	BATADV_CMD_TP_METER_CANCEL,

	/**
	 * @BATADV_CMD_GET_ROUTING_ALGOS: Query the list of routing algorithms.
	 */
	BATADV_CMD_GET_ROUTING_ALGOS,

	/**
	 * @BATADV_CMD_GET_HARDIFS: Query list of hard interfaces
	 */
	BATADV_CMD_GET_HARDIFS,

	/**
	 * @BATADV_CMD_GET_TRANSTABLE_LOCAL: Query list of local translations
	 */
	BATADV_CMD_GET_TRANSTABLE_LOCAL,

	/**
	 * @BATADV_CMD_GET_TRANSTABLE_GLOBAL: Query list of global translations
	 */
	BATADV_CMD_GET_TRANSTABLE_GLOBAL,

	/**
	 * @BATADV_CMD_GET_ORIGINATORS: Query list of originators
	 */
	BATADV_CMD_GET_ORIGINATORS,

	/**
	 * @BATADV_CMD_GET_NEIGHBORS: Query list of neighbours
	 */
	BATADV_CMD_GET_NEIGHBORS,

	/**
	 * @BATADV_CMD_GET_GATEWAYS: Query list of gateways
	 */
	BATADV_CMD_GET_GATEWAYS,

	/**
	 * @BATADV_CMD_GET_BLA_CLAIM: Query list of bridge loop avoidance claims
	 */
	BATADV_CMD_GET_BLA_CLAIM,

	/**
	 * @BATADV_CMD_GET_BLA_BACKBONE: Query list of bridge loop avoidance
	 * backbones
	 */
	BATADV_CMD_GET_BLA_BACKBONE,

	/**
	 * @BATADV_CMD_GET_DAT_CACHE: Query list of DAT cache entries
	 */
	BATADV_CMD_GET_DAT_CACHE,

	/**
	 * @BATADV_CMD_GET_MCAST_FLAGS: Query list of multicast flags
	 */
	BATADV_CMD_GET_MCAST_FLAGS,

	/* add new commands above here */

	/**
	 * @__BATADV_CMD_AFTER_LAST: internal use
	 */
	__BATADV_CMD_AFTER_LAST,

	/**
	 * @BATADV_CMD_MAX: highest used command number
	 */
	BATADV_CMD_MAX = __BATADV_CMD_AFTER_LAST - 1
};

/**
 * enum batadv_tp_meter_reason - reason of a tp meter test run stop
 */
enum batadv_tp_meter_reason {
	/**
	 * @BATADV_TP_REASON_COMPLETE: sender finished tp run
	 */
	BATADV_TP_REASON_COMPLETE		= 3,

	/**
	 * @BATADV_TP_REASON_CANCEL: sender was stopped during run
	 */
	BATADV_TP_REASON_CANCEL			= 4,

	/* error status >= 128 */

	/**
	 * @BATADV_TP_REASON_DST_UNREACHABLE: receiver could not be reached or
	 * didn't answer
	 */
	BATADV_TP_REASON_DST_UNREACHABLE	= 128,

	/**
	 * @BATADV_TP_REASON_RESEND_LIMIT: (unused) sender retry reached limit
	 */
	BATADV_TP_REASON_RESEND_LIMIT		= 129,

	/**
	 * @BATADV_TP_REASON_ALREADY_ONGOING: test to or from the same node
	 * already ongoing
	 */
	BATADV_TP_REASON_ALREADY_ONGOING	= 130,

	/**
	 * @BATADV_TP_REASON_MEMORY_ERROR: test was stopped due to low memory
	 */
	BATADV_TP_REASON_MEMORY_ERROR		= 131,

	/**
	 * @BATADV_TP_REASON_CANT_SEND: failed to send via outgoing interface
	 */
	BATADV_TP_REASON_CANT_SEND		= 132,

	/**
	 * @BATADV_TP_REASON_TOO_MANY: too many ongoing sessions
	 */
	BATADV_TP_REASON_TOO_MANY		= 133,
};

#endif /* _LINUX_BATMAN_ADV_H_ */