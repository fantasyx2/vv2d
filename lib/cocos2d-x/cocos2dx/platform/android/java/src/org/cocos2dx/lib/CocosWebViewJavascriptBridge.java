package org.cocos2dx.lib;
public class CocosWebViewJavascriptBridge{
	static char[] js_data={
	0x3b,0x28,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x28,0x29,0x20,0x7b,0xd,0xa,
	0x9,0x69,0x66,0x20,0x28,0x77,0x69,0x6e,0x64,0x6f,0x77,0x2e,0x57,0x65,0x62,0x56,
	0x69,0x65,0x77,0x4a,0x61,0x76,0x61,0x73,0x63,0x72,0x69,0x70,0x74,0x42,0x72,0x69,
	0x64,0x67,0x65,0x29,0x20,0x7b,0x20,0x72,0x65,0x74,0x75,0x72,0x6e,0x20,0x7d,0xd,
	0xa,0x9,0x76,0x61,0x72,0x20,0x6d,0x65,0x73,0x73,0x61,0x67,0x69,0x6e,0x67,0x49,
	0x66,0x72,0x61,0x6d,0x65,0xd,0xa,0x9,0x76,0x61,0x72,0x20,0x73,0x65,0x6e,0x64,
	0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x51,0x75,0x65,0x75,0x65,0x20,0x3d,0x20,0x5b,
	0x5d,0xd,0xa,0x9,0x76,0x61,0x72,0x20,0x72,0x65,0x63,0x65,0x69,0x76,0x65,0x4d,
	0x65,0x73,0x73,0x61,0x67,0x65,0x51,0x75,0x65,0x75,0x65,0x20,0x3d,0x20,0x5b,0x5d,
	0xd,0xa,0x9,0x76,0x61,0x72,0x20,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x48,0x61,
	0x6e,0x64,0x6c,0x65,0x72,0x73,0x20,0x3d,0x20,0x7b,0x7d,0xd,0xa,0x9,0xd,0xa,
	0x9,0x76,0x61,0x72,0x20,0x43,0x55,0x53,0x54,0x4f,0x4d,0x5f,0x50,0x52,0x4f,0x54,
	0x4f,0x43,0x4f,0x4c,0x5f,0x53,0x43,0x48,0x45,0x4d,0x45,0x20,0x3d,0x20,0x27,0x77,
	0x76,0x6a,0x62,0x73,0x63,0x68,0x65,0x6d,0x65,0x27,0xd,0xa,0x9,0x76,0x61,0x72,
	0x20,0x51,0x55,0x45,0x55,0x45,0x5f,0x48,0x41,0x53,0x5f,0x4d,0x45,0x53,0x53,0x41,
	0x47,0x45,0x20,0x3d,0x20,0x27,0x5f,0x5f,0x57,0x56,0x4a,0x42,0x5f,0x51,0x55,0x45,
	0x55,0x45,0x5f,0x4d,0x45,0x53,0x53,0x41,0x47,0x45,0x5f,0x5f,0x27,0xd,0xa,0x9,
	0xd,0xa,0x9,0x76,0x61,0x72,0x20,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x43,
	0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x73,0x20,0x3d,0x20,0x7b,0x7d,0xd,0xa,0x9,
	0x76,0x61,0x72,0x20,0x75,0x6e,0x69,0x71,0x75,0x65,0x49,0x64,0x20,0x3d,0x20,0x31,
	0xd,0xa,0x9,0xd,0xa,0x9,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x20,0x5f,
	0x63,0x72,0x65,0x61,0x74,0x65,0x51,0x75,0x65,0x75,0x65,0x52,0x65,0x61,0x64,0x79,
	0x49,0x66,0x72,0x61,0x6d,0x65,0x28,0x64,0x6f,0x63,0x29,0x20,0x7b,0xd,0xa,0x9,
	0x9,0x6d,0x65,0x73,0x73,0x61,0x67,0x69,0x6e,0x67,0x49,0x66,0x72,0x61,0x6d,0x65,
	0x20,0x3d,0x20,0x64,0x6f,0x63,0x2e,0x63,0x72,0x65,0x61,0x74,0x65,0x45,0x6c,0x65,
	0x6d,0x65,0x6e,0x74,0x28,0x27,0x69,0x66,0x72,0x61,0x6d,0x65,0x27,0x29,0xd,0xa,
	0x9,0x9,0x6d,0x65,0x73,0x73,0x61,0x67,0x69,0x6e,0x67,0x49,0x66,0x72,0x61,0x6d,
	0x65,0x2e,0x73,0x74,0x79,0x6c,0x65,0x2e,0x64,0x69,0x73,0x70,0x6c,0x61,0x79,0x20,
	0x3d,0x20,0x27,0x6e,0x6f,0x6e,0x65,0x27,0xd,0xa,0x9,0x9,0x64,0x6f,0x63,0x2e,
	0x64,0x6f,0x63,0x75,0x6d,0x65,0x6e,0x74,0x45,0x6c,0x65,0x6d,0x65,0x6e,0x74,0x2e,
	0x61,0x70,0x70,0x65,0x6e,0x64,0x43,0x68,0x69,0x6c,0x64,0x28,0x6d,0x65,0x73,0x73,
	0x61,0x67,0x69,0x6e,0x67,0x49,0x66,0x72,0x61,0x6d,0x65,0x29,0xd,0xa,0x9,0x7d,
	0xd,0xa,0xd,0xa,0x9,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x20,0x69,0x6e,
	0x69,0x74,0x28,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x48,0x61,0x6e,0x64,0x6c,0x65,
	0x72,0x29,0x20,0x7b,0xd,0xa,0x9,0x9,0x69,0x66,0x20,0x28,0x57,0x65,0x62,0x56,
	0x69,0x65,0x77,0x4a,0x61,0x76,0x61,0x73,0x63,0x72,0x69,0x70,0x74,0x42,0x72,0x69,
	0x64,0x67,0x65,0x2e,0x5f,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x48,0x61,0x6e,0x64,
	0x6c,0x65,0x72,0x29,0x20,0x7b,0x20,0x74,0x68,0x72,0x6f,0x77,0x20,0x6e,0x65,0x77,
	0x20,0x45,0x72,0x72,0x6f,0x72,0x28,0x27,0x57,0x65,0x62,0x56,0x69,0x65,0x77,0x4a,
	0x61,0x76,0x61,0x73,0x63,0x72,0x69,0x70,0x74,0x42,0x72,0x69,0x64,0x67,0x65,0x2e,
	0x69,0x6e,0x69,0x74,0x20,0x63,0x61,0x6c,0x6c,0x65,0x64,0x20,0x74,0x77,0x69,0x63,
	0x65,0x27,0x29,0x20,0x7d,0xd,0xa,0x9,0x9,0x57,0x65,0x62,0x56,0x69,0x65,0x77,
	0x4a,0x61,0x76,0x61,0x73,0x63,0x72,0x69,0x70,0x74,0x42,0x72,0x69,0x64,0x67,0x65,
	0x2e,0x5f,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x48,0x61,0x6e,0x64,0x6c,0x65,0x72,
	0x20,0x3d,0x20,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x48,0x61,0x6e,0x64,0x6c,0x65,
	0x72,0xd,0xa,0x9,0x9,0x76,0x61,0x72,0x20,0x72,0x65,0x63,0x65,0x69,0x76,0x65,
	0x64,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x73,0x20,0x3d,0x20,0x72,0x65,0x63,0x65,
	0x69,0x76,0x65,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x51,0x75,0x65,0x75,0x65,0xd,
	0xa,0x9,0x9,0x72,0x65,0x63,0x65,0x69,0x76,0x65,0x4d,0x65,0x73,0x73,0x61,0x67,
	0x65,0x51,0x75,0x65,0x75,0x65,0x20,0x3d,0x20,0x6e,0x75,0x6c,0x6c,0xd,0xa,0x9,
	0x9,0x66,0x6f,0x72,0x20,0x28,0x76,0x61,0x72,0x20,0x69,0x3d,0x30,0x3b,0x20,0x69,
	0x3c,0x72,0x65,0x63,0x65,0x69,0x76,0x65,0x64,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,
	0x73,0x2e,0x6c,0x65,0x6e,0x67,0x74,0x68,0x3b,0x20,0x69,0x2b,0x2b,0x29,0x20,0x7b,
	0xd,0xa,0x9,0x9,0x9,0x5f,0x64,0x69,0x73,0x70,0x61,0x74,0x63,0x68,0x4d,0x65,
	0x73,0x73,0x61,0x67,0x65,0x46,0x72,0x6f,0x6d,0x4f,0x62,0x6a,0x43,0x28,0x72,0x65,
	0x63,0x65,0x69,0x76,0x65,0x64,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x73,0x5b,0x69,
	0x5d,0x29,0xd,0xa,0x9,0x9,0x7d,0xd,0xa,0x9,0x7d,0xd,0xa,0xd,0xa,0x9,
	0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x20,0x73,0x65,0x6e,0x64,0x28,0x64,0x61,
	0x74,0x61,0x2c,0x20,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x43,0x61,0x6c,0x6c,
	0x62,0x61,0x63,0x6b,0x29,0x20,0x7b,0xd,0xa,0x9,0x9,0x5f,0x64,0x6f,0x53,0x65,
	0x6e,0x64,0x28,0x7b,0x20,0x64,0x61,0x74,0x61,0x3a,0x64,0x61,0x74,0x61,0x20,0x7d,
	0x2c,0x20,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,
	0x63,0x6b,0x29,0xd,0xa,0x9,0x7d,0xd,0xa,0x9,0xd,0xa,0x9,0x66,0x75,0x6e,
	0x63,0x74,0x69,0x6f,0x6e,0x20,0x72,0x65,0x67,0x69,0x73,0x74,0x65,0x72,0x48,0x61,
	0x6e,0x64,0x6c,0x65,0x72,0x28,0x68,0x61,0x6e,0x64,0x6c,0x65,0x72,0x4e,0x61,0x6d,
	0x65,0x2c,0x20,0x68,0x61,0x6e,0x64,0x6c,0x65,0x72,0x29,0x20,0x7b,0xd,0xa,0x9,
	0x9,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x48,0x61,0x6e,0x64,0x6c,0x65,0x72,0x73,
	0x5b,0x68,0x61,0x6e,0x64,0x6c,0x65,0x72,0x4e,0x61,0x6d,0x65,0x5d,0x20,0x3d,0x20,
	0x68,0x61,0x6e,0x64,0x6c,0x65,0x72,0xd,0xa,0x9,0x7d,0xd,0xa,0x9,0xd,0xa,
	0x9,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x20,0x63,0x61,0x6c,0x6c,0x48,0x61,
	0x6e,0x64,0x6c,0x65,0x72,0x28,0x68,0x61,0x6e,0x64,0x6c,0x65,0x72,0x4e,0x61,0x6d,
	0x65,0x2c,0x20,0x64,0x61,0x74,0x61,0x2c,0x20,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,
	0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x29,0x20,0x7b,0xd,0xa,0x9,0x9,
	0x5f,0x64,0x6f,0x53,0x65,0x6e,0x64,0x28,0x7b,0x20,0x68,0x61,0x6e,0x64,0x6c,0x65,
	0x72,0x4e,0x61,0x6d,0x65,0x3a,0x68,0x61,0x6e,0x64,0x6c,0x65,0x72,0x4e,0x61,0x6d,
	0x65,0x2c,0x20,0x64,0x61,0x74,0x61,0x3a,0x64,0x61,0x74,0x61,0x20,0x7d,0x2c,0x20,
	0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,
	0x29,0xd,0xa,0x9,0x7d,0xd,0xa,0x9,0xd,0xa,0x9,0x66,0x75,0x6e,0x63,0x74,
	0x69,0x6f,0x6e,0x20,0x5f,0x64,0x6f,0x53,0x65,0x6e,0x64,0x28,0x6d,0x65,0x73,0x73,
	0x61,0x67,0x65,0x2c,0x20,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x43,0x61,0x6c,
	0x6c,0x62,0x61,0x63,0x6b,0x29,0x20,0x7b,0xd,0xa,0x9,0x9,0x69,0x66,0x20,0x28,
	0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,
	0x29,0x20,0x7b,0xd,0xa,0x9,0x9,0x9,0x76,0x61,0x72,0x20,0x63,0x61,0x6c,0x6c,
	0x62,0x61,0x63,0x6b,0x49,0x64,0x20,0x3d,0x20,0x27,0x63,0x62,0x5f,0x27,0x2b,0x28,
	0x75,0x6e,0x69,0x71,0x75,0x65,0x49,0x64,0x2b,0x2b,0x29,0x2b,0x27,0x5f,0x27,0x2b,
	0x6e,0x65,0x77,0x20,0x44,0x61,0x74,0x65,0x28,0x29,0x2e,0x67,0x65,0x74,0x54,0x69,
	0x6d,0x65,0x28,0x29,0xd,0xa,0x9,0x9,0x9,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,
	0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x73,0x5b,0x63,0x61,0x6c,0x6c,0x62,
	0x61,0x63,0x6b,0x49,0x64,0x5d,0x20,0x3d,0x20,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,
	0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0xd,0xa,0x9,0x9,0x9,0x6d,0x65,
	0x73,0x73,0x61,0x67,0x65,0x5b,0x27,0x63,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x49,
	0x64,0x27,0x5d,0x20,0x3d,0x20,0x63,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x49,0x64,
	0xd,0xa,0x9,0x9,0x7d,0xd,0xa,0x9,0x9,0x73,0x65,0x6e,0x64,0x4d,0x65,0x73,
	0x73,0x61,0x67,0x65,0x51,0x75,0x65,0x75,0x65,0x2e,0x70,0x75,0x73,0x68,0x28,0x6d,
	0x65,0x73,0x73,0x61,0x67,0x65,0x29,0xd,0xa,0x9,0x9,0x6d,0x65,0x73,0x73,0x61,
	0x67,0x69,0x6e,0x67,0x49,0x66,0x72,0x61,0x6d,0x65,0x2e,0x73,0x72,0x63,0x20,0x3d,
	0x20,0x43,0x55,0x53,0x54,0x4f,0x4d,0x5f,0x50,0x52,0x4f,0x54,0x4f,0x43,0x4f,0x4c,
	0x5f,0x53,0x43,0x48,0x45,0x4d,0x45,0x20,0x2b,0x20,0x27,0x3a,0x2f,0x2f,0x27,0x20,
	0x2b,0x20,0x51,0x55,0x45,0x55,0x45,0x5f,0x48,0x41,0x53,0x5f,0x4d,0x45,0x53,0x53,
	0x41,0x47,0x45,0xd,0xa,0x9,0x7d,0xd,0xa,0xd,0xa,0x9,0x66,0x75,0x6e,0x63,
	0x74,0x69,0x6f,0x6e,0x20,0x5f,0x66,0x65,0x74,0x63,0x68,0x51,0x75,0x65,0x75,0x65,
	0x28,0x29,0x20,0x7b,0xd,0xa,0x9,0x9,0x76,0x61,0x72,0x20,0x6d,0x65,0x73,0x73,
	0x61,0x67,0x65,0x51,0x75,0x65,0x75,0x65,0x53,0x74,0x72,0x69,0x6e,0x67,0x20,0x3d,
	0x20,0x4a,0x53,0x4f,0x4e,0x2e,0x73,0x74,0x72,0x69,0x6e,0x67,0x69,0x66,0x79,0x28,
	0x73,0x65,0x6e,0x64,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x51,0x75,0x65,0x75,0x65,
	0x29,0xd,0xa,0x9,0x9,0x73,0x65,0x6e,0x64,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,
	0x51,0x75,0x65,0x75,0x65,0x20,0x3d,0x20,0x5b,0x5d,0xd,0xa,0x9,0x9,0x72,0x65,
	0x74,0x75,0x72,0x6e,0x20,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x51,0x75,0x65,0x75,
	0x65,0x53,0x74,0x72,0x69,0x6e,0x67,0xd,0xa,0x9,0x7d,0xd,0xa,0xd,0xa,0x9,
	0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x20,0x5f,0x64,0x69,0x73,0x70,0x61,0x74,
	0x63,0x68,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x46,0x72,0x6f,0x6d,0x4f,0x62,0x6a,
	0x43,0x28,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x4a,0x53,0x4f,0x4e,0x29,0x20,0x7b,
	0xd,0xa,0x9,0x9,0x73,0x65,0x74,0x54,0x69,0x6d,0x65,0x6f,0x75,0x74,0x28,0x66,
	0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x20,0x5f,0x74,0x69,0x6d,0x65,0x6f,0x75,0x74,
	0x44,0x69,0x73,0x70,0x61,0x74,0x63,0x68,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x46,
	0x72,0x6f,0x6d,0x4f,0x62,0x6a,0x43,0x28,0x29,0x20,0x7b,0xd,0xa,0x9,0x9,0x9,
	0x76,0x61,0x72,0x20,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x20,0x3d,0x20,0x4a,0x53,
	0x4f,0x4e,0x2e,0x70,0x61,0x72,0x73,0x65,0x28,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,
	0x4a,0x53,0x4f,0x4e,0x29,0xd,0xa,0x9,0x9,0x9,0x76,0x61,0x72,0x20,0x6d,0x65,
	0x73,0x73,0x61,0x67,0x65,0x48,0x61,0x6e,0x64,0x6c,0x65,0x72,0xd,0xa,0x9,0x9,
	0x9,0xd,0xa,0x9,0x9,0x9,0x69,0x66,0x20,0x28,0x6d,0x65,0x73,0x73,0x61,0x67,
	0x65,0x2e,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x49,0x64,0x29,0x20,0x7b,0xd,
	0xa,0x9,0x9,0x9,0x9,0x76,0x61,0x72,0x20,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,
	0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x20,0x3d,0x20,0x72,0x65,0x73,0x70,
	0x6f,0x6e,0x73,0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x73,0x5b,0x6d,0x65,
	0x73,0x73,0x61,0x67,0x65,0x2e,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x49,0x64,
	0x5d,0xd,0xa,0x9,0x9,0x9,0x9,0x69,0x66,0x20,0x28,0x21,0x72,0x65,0x73,0x70,
	0x6f,0x6e,0x73,0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x29,0x20,0x7b,0x20,
	0x72,0x65,0x74,0x75,0x72,0x6e,0x3b,0x20,0x7d,0xd,0xa,0x9,0x9,0x9,0x9,0x72,
	0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x28,
	0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x2e,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,
	0x44,0x61,0x74,0x61,0x29,0xd,0xa,0x9,0x9,0x9,0x9,0x64,0x65,0x6c,0x65,0x74,
	0x65,0x20,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,
	0x63,0x6b,0x73,0x5b,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x2e,0x72,0x65,0x73,0x70,
	0x6f,0x6e,0x73,0x65,0x49,0x64,0x5d,0xd,0xa,0x9,0x9,0x9,0x7d,0x20,0x65,0x6c,
	0x73,0x65,0x20,0x7b,0xd,0xa,0x9,0x9,0x9,0x9,0x76,0x61,0x72,0x20,0x72,0x65,
	0x73,0x70,0x6f,0x6e,0x73,0x65,0x43,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0xd,0xa,
	0x9,0x9,0x9,0x9,0x69,0x66,0x20,0x28,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x2e,
	0x63,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x49,0x64,0x29,0x20,0x7b,0xd,0xa,0x9,
	0x9,0x9,0x9,0x9,0x76,0x61,0x72,0x20,0x63,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,
	0x52,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x49,0x64,0x20,0x3d,0x20,0x6d,0x65,0x73,
	0x73,0x61,0x67,0x65,0x2e,0x63,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x49,0x64,0xd,
	0xa,0x9,0x9,0x9,0x9,0x9,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x43,0x61,
	0x6c,0x6c,0x62,0x61,0x63,0x6b,0x20,0x3d,0x20,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,
	0x6e,0x28,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x44,0x61,0x74,0x61,0x29,0x20,
	0x7b,0xd,0xa,0x9,0x9,0x9,0x9,0x9,0x9,0x5f,0x64,0x6f,0x53,0x65,0x6e,0x64,
	0x28,0x7b,0x20,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x49,0x64,0x3a,0x63,0x61,
	0x6c,0x6c,0x62,0x61,0x63,0x6b,0x52,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x49,0x64,
	0x2c,0x20,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x44,0x61,0x74,0x61,0x3a,0x72,
	0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x44,0x61,0x74,0x61,0x20,0x7d,0x29,0xd,0xa,
	0x9,0x9,0x9,0x9,0x9,0x7d,0xd,0xa,0x9,0x9,0x9,0x9,0x7d,0xd,0xa,0x9,
	0x9,0x9,0x9,0xd,0xa,0x9,0x9,0x9,0x9,0x76,0x61,0x72,0x20,0x68,0x61,0x6e,
	0x64,0x6c,0x65,0x72,0x20,0x3d,0x20,0x57,0x65,0x62,0x56,0x69,0x65,0x77,0x4a,0x61,
	0x76,0x61,0x73,0x63,0x72,0x69,0x70,0x74,0x42,0x72,0x69,0x64,0x67,0x65,0x2e,0x5f,
	0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x48,0x61,0x6e,0x64,0x6c,0x65,0x72,0xd,0xa,
	0x9,0x9,0x9,0x9,0x69,0x66,0x20,0x28,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x2e,
	0x68,0x61,0x6e,0x64,0x6c,0x65,0x72,0x4e,0x61,0x6d,0x65,0x29,0x20,0x7b,0xd,0xa,
	0x9,0x9,0x9,0x9,0x9,0x68,0x61,0x6e,0x64,0x6c,0x65,0x72,0x20,0x3d,0x20,0x6d,
	0x65,0x73,0x73,0x61,0x67,0x65,0x48,0x61,0x6e,0x64,0x6c,0x65,0x72,0x73,0x5b,0x6d,
	0x65,0x73,0x73,0x61,0x67,0x65,0x2e,0x68,0x61,0x6e,0x64,0x6c,0x65,0x72,0x4e,0x61,
	0x6d,0x65,0x5d,0xd,0xa,0x9,0x9,0x9,0x9,0x7d,0xd,0xa,0x9,0x9,0x9,0x9,
	0xd,0xa,0x9,0x9,0x9,0x9,0x74,0x72,0x79,0x20,0x7b,0xd,0xa,0x9,0x9,0x9,
	0x9,0x9,0x68,0x61,0x6e,0x64,0x6c,0x65,0x72,0x28,0x6d,0x65,0x73,0x73,0x61,0x67,
	0x65,0x2e,0x64,0x61,0x74,0x61,0x2c,0x20,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,
	0x43,0x61,0x6c,0x6c,0x62,0x61,0x63,0x6b,0x29,0xd,0xa,0x9,0x9,0x9,0x9,0x7d,
	0x20,0x63,0x61,0x74,0x63,0x68,0x28,0x65,0x78,0x63,0x65,0x70,0x74,0x69,0x6f,0x6e,
	0x29,0x20,0x7b,0xd,0xa,0x9,0x9,0x9,0x9,0x9,0x69,0x66,0x20,0x28,0x74,0x79,
	0x70,0x65,0x6f,0x66,0x20,0x63,0x6f,0x6e,0x73,0x6f,0x6c,0x65,0x20,0x21,0x3d,0x20,
	0x27,0x75,0x6e,0x64,0x65,0x66,0x69,0x6e,0x65,0x64,0x27,0x29,0x20,0x7b,0xd,0xa,
	0x9,0x9,0x9,0x9,0x9,0x9,0x63,0x6f,0x6e,0x73,0x6f,0x6c,0x65,0x2e,0x6c,0x6f,
	0x67,0x28,0x22,0x57,0x65,0x62,0x56,0x69,0x65,0x77,0x4a,0x61,0x76,0x61,0x73,0x63,
	0x72,0x69,0x70,0x74,0x42,0x72,0x69,0x64,0x67,0x65,0x3a,0x20,0x57,0x41,0x52,0x4e,
	0x49,0x4e,0x47,0x3a,0x20,0x6a,0x61,0x76,0x61,0x73,0x63,0x72,0x69,0x70,0x74,0x20,
	0x68,0x61,0x6e,0x64,0x6c,0x65,0x72,0x20,0x74,0x68,0x72,0x65,0x77,0x2e,0x22,0x2c,
	0x20,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x2c,0x20,0x65,0x78,0x63,0x65,0x70,0x74,
	0x69,0x6f,0x6e,0x29,0xd,0xa,0x9,0x9,0x9,0x9,0x9,0x7d,0xd,0xa,0x9,0x9,
	0x9,0x9,0x7d,0xd,0xa,0x9,0x9,0x9,0x7d,0xd,0xa,0x9,0x9,0x7d,0x29,0xd,
	0xa,0x9,0x7d,0xd,0xa,0x9,0xd,0xa,0x9,0x66,0x75,0x6e,0x63,0x74,0x69,0x6f,
	0x6e,0x20,0x5f,0x68,0x61,0x6e,0x64,0x6c,0x65,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,
	0x46,0x72,0x6f,0x6d,0x4f,0x62,0x6a,0x43,0x28,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,
	0x4a,0x53,0x4f,0x4e,0x29,0x20,0x7b,0xd,0xa,0x9,0x9,0x69,0x66,0x20,0x28,0x72,
	0x65,0x63,0x65,0x69,0x76,0x65,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x51,0x75,0x65,
	0x75,0x65,0x29,0x20,0x7b,0xd,0xa,0x9,0x9,0x9,0x72,0x65,0x63,0x65,0x69,0x76,
	0x65,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x51,0x75,0x65,0x75,0x65,0x2e,0x70,0x75,
	0x73,0x68,0x28,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,0x4a,0x53,0x4f,0x4e,0x29,0xd,
	0xa,0x9,0x9,0x7d,0x20,0x65,0x6c,0x73,0x65,0x20,0x7b,0xd,0xa,0x9,0x9,0x9,
	0x5f,0x64,0x69,0x73,0x70,0x61,0x74,0x63,0x68,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,
	0x46,0x72,0x6f,0x6d,0x4f,0x62,0x6a,0x43,0x28,0x6d,0x65,0x73,0x73,0x61,0x67,0x65,
	0x4a,0x53,0x4f,0x4e,0x29,0xd,0xa,0x9,0x9,0x7d,0xd,0xa,0x9,0x7d,0xd,0xa,
	0xd,0xa,0x9,0x77,0x69,0x6e,0x64,0x6f,0x77,0x2e,0x57,0x65,0x62,0x56,0x69,0x65,
	0x77,0x4a,0x61,0x76,0x61,0x73,0x63,0x72,0x69,0x70,0x74,0x42,0x72,0x69,0x64,0x67,
	0x65,0x20,0x3d,0x20,0x7b,0xd,0xa,0x9,0x9,0x69,0x6e,0x69,0x74,0x3a,0x20,0x69,
	0x6e,0x69,0x74,0x2c,0xd,0xa,0x9,0x9,0x73,0x65,0x6e,0x64,0x3a,0x20,0x73,0x65,
	0x6e,0x64,0x2c,0xd,0xa,0x9,0x9,0x72,0x65,0x67,0x69,0x73,0x74,0x65,0x72,0x48,
	0x61,0x6e,0x64,0x6c,0x65,0x72,0x3a,0x20,0x72,0x65,0x67,0x69,0x73,0x74,0x65,0x72,
	0x48,0x61,0x6e,0x64,0x6c,0x65,0x72,0x2c,0xd,0xa,0x9,0x9,0x63,0x61,0x6c,0x6c,
	0x48,0x61,0x6e,0x64,0x6c,0x65,0x72,0x3a,0x20,0x63,0x61,0x6c,0x6c,0x48,0x61,0x6e,
	0x64,0x6c,0x65,0x72,0x2c,0xd,0xa,0x9,0x9,0x5f,0x66,0x65,0x74,0x63,0x68,0x51,
	0x75,0x65,0x75,0x65,0x3a,0x20,0x5f,0x66,0x65,0x74,0x63,0x68,0x51,0x75,0x65,0x75,
	0x65,0x2c,0xd,0xa,0x9,0x9,0x5f,0x68,0x61,0x6e,0x64,0x6c,0x65,0x4d,0x65,0x73,
	0x73,0x61,0x67,0x65,0x46,0x72,0x6f,0x6d,0x4f,0x62,0x6a,0x43,0x3a,0x20,0x5f,0x68,
	0x61,0x6e,0x64,0x6c,0x65,0x4d,0x65,0x73,0x73,0x61,0x67,0x65,0x46,0x72,0x6f,0x6d,
	0x4f,0x62,0x6a,0x43,0xd,0xa,0x9,0x7d,0xd,0xa,0xd,0xa,0x9,0x76,0x61,0x72,
	0x20,0x64,0x6f,0x63,0x20,0x3d,0x20,0x64,0x6f,0x63,0x75,0x6d,0x65,0x6e,0x74,0xd,
	0xa,0x9,0x5f,0x63,0x72,0x65,0x61,0x74,0x65,0x51,0x75,0x65,0x75,0x65,0x52,0x65,
	0x61,0x64,0x79,0x49,0x66,0x72,0x61,0x6d,0x65,0x28,0x64,0x6f,0x63,0x29,0xd,0xa,
	0x9,0x76,0x61,0x72,0x20,0x72,0x65,0x61,0x64,0x79,0x45,0x76,0x65,0x6e,0x74,0x20,
	0x3d,0x20,0x64,0x6f,0x63,0x2e,0x63,0x72,0x65,0x61,0x74,0x65,0x45,0x76,0x65,0x6e,
	0x74,0x28,0x27,0x45,0x76,0x65,0x6e,0x74,0x73,0x27,0x29,0xd,0xa,0x9,0x72,0x65,
	0x61,0x64,0x79,0x45,0x76,0x65,0x6e,0x74,0x2e,0x69,0x6e,0x69,0x74,0x45,0x76,0x65,
	0x6e,0x74,0x28,0x27,0x57,0x65,0x62,0x56,0x69,0x65,0x77,0x4a,0x61,0x76,0x61,0x73,
	0x63,0x72,0x69,0x70,0x74,0x42,0x72,0x69,0x64,0x67,0x65,0x52,0x65,0x61,0x64,0x79,
	0x27,0x29,0xd,0xa,0x9,0x72,0x65,0x61,0x64,0x79,0x45,0x76,0x65,0x6e,0x74,0x2e,
	0x62,0x72,0x69,0x64,0x67,0x65,0x20,0x3d,0x20,0x57,0x65,0x62,0x56,0x69,0x65,0x77,
	0x4a,0x61,0x76,0x61,0x73,0x63,0x72,0x69,0x70,0x74,0x42,0x72,0x69,0x64,0x67,0x65,
	0xd,0xa,0x9,0x64,0x6f,0x63,0x2e,0x64,0x69,0x73,0x70,0x61,0x74,0x63,0x68,0x45,
	0x76,0x65,0x6e,0x74,0x28,0x72,0x65,0x61,0x64,0x79,0x45,0x76,0x65,0x6e,0x74,0x29,
	0xd,0xa,0x7d,0x29,0x28,0x29,0x3b,0xd,0xa	
};
	public static String getJsBridgeCode(){
		return new String(js_data);
	}
}