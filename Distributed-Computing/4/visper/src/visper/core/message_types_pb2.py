# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# NO CHECKED-IN PROTOBUF GENCODE
# source: message_types.proto
# Protobuf Python Version: 5.27.0
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import runtime_version as _runtime_version
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
_runtime_version.ValidateProtobufRuntimeVersion(
    _runtime_version.Domain.PUBLIC,
    5,
    27,
    0,
    '',
    'message_types.proto'
)
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x13message_types.proto\x12\rmessage_types\"\"\n\x04\x42ody\x12\x0c\n\x04type\x18\x01 \x01(\t\x12\x0c\n\x04\x64\x61ta\x18\x02 \x01(\x0c\"W\n\tHandshake\x12\x0f\n\x07msg_seq\x18\x01 \x01(\x03\x12\x11\n\tsender_id\x18\x02 \x01(\t\x12\x13\n\x0bsender_name\x18\x03 \x01(\t\x12\x11\n\ttimestamp\x18\x04 \x01(\x03\"1\n\tHeartbeat\x12\x11\n\tsender_id\x18\x01 \x01(\t\x12\x11\n\ttimestamp\x18\x02 \x01(\x03\"z\n\x08Proposal\x12\x0e\n\x06msg_id\x18\x01 \x01(\t\x12\x11\n\tsender_id\x18\x02 \x01(\t\x12\x17\n\x0fprev_sender_ids\x18\x03 \x03(\t\x12\x10\n\x08topic_id\x18\x04 \x01(\t\x12\r\n\x05topic\x18\x05 \x01(\x03\x12\x11\n\ttimestamp\x18\x06 \x01(\x03\"x\n\x04Vote\x12\x0e\n\x06msg_id\x18\x01 \x01(\t\x12\x11\n\tsender_id\x18\x02 \x01(\t\x12\x19\n\x11next_receiver_ids\x18\x03 \x03(\t\x12\x10\n\x08topic_id\x18\x04 \x01(\t\x12\r\n\x05value\x18\x05 \x01(\x08\x12\x11\n\ttimestamp\x18\x06 \x01(\x03\"t\n\x06Result\x12\x0e\n\x06msg_id\x18\x01 \x01(\t\x12\x0f\n\x07msg_seq\x18\x02 \x01(\x03\x12\x11\n\tsender_id\x18\x03 \x01(\t\x12#\n\x06\x62odies\x18\x06 \x03(\x0b\x32\x13.message_types.Body\x12\x11\n\ttimestamp\x18\x07 \x01(\x03\"\xbf\x01\n\x07Message\x12-\n\theartbeat\x18\x02 \x01(\x0b\x32\x18.message_types.HeartbeatH\x00\x12+\n\x08proposal\x18\x03 \x01(\x0b\x32\x17.message_types.ProposalH\x00\x12#\n\x04vote\x18\x04 \x01(\x0b\x32\x13.message_types.VoteH\x00\x12\'\n\x06result\x18\x05 \x01(\x0b\x32\x15.message_types.ResultH\x00\x42\n\n\x08msg_typeb\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'message_types_pb2', _globals)
if not _descriptor._USE_C_DESCRIPTORS:
  DESCRIPTOR._loaded_options = None
  _globals['_BODY']._serialized_start=38
  _globals['_BODY']._serialized_end=72
  _globals['_HANDSHAKE']._serialized_start=74
  _globals['_HANDSHAKE']._serialized_end=161
  _globals['_HEARTBEAT']._serialized_start=163
  _globals['_HEARTBEAT']._serialized_end=212
  _globals['_PROPOSAL']._serialized_start=214
  _globals['_PROPOSAL']._serialized_end=336
  _globals['_VOTE']._serialized_start=338
  _globals['_VOTE']._serialized_end=458
  _globals['_RESULT']._serialized_start=460
  _globals['_RESULT']._serialized_end=576
  _globals['_MESSAGE']._serialized_start=579
  _globals['_MESSAGE']._serialized_end=770
# @@protoc_insertion_point(module_scope)