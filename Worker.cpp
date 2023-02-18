//
// Created by Kosho Owa on 2019-07-25.
//


#include "Worker.h"

unsigned char cflow_cap[] = {
        0x00, 0x09,
        0x00, 0x12, 0xc3, 0x0b, 0xfb, 0x2a, 0x53, 0xe0, 0xbd, 0x96, 0xa5, 0xba,
        0xb7, 0xef, 0x00, 0x00, 0x00, 0xc8, 0x00, 0x00, 0x00, 0x90, 0x01, 0x03,
        0x00, 0x09, 0x00, 0x08, 0x00, 0x04, 0x00, 0xe1, 0x00, 0x04, 0x00, 0xea,
        0x00, 0x04, 0x00, 0x04, 0x00, 0x01, 0x00, 0xe6, 0x00, 0x01, 0x01, 0x43,
        0x00, 0x08, 0x01, 0x69, 0x00, 0x02, 0x01, 0x6b, 0x00, 0x02, 0x01, 0x6c,
        0x00, 0x02, 0x01, 0x02, 0x00, 0x02, 0x01, 0x1b, 0x00, 0x04, 0x00, 0xe6,
        0x00, 0x01, 0x01, 0x01, 0x00, 0x08, 0x00, 0x08, 0x00, 0x04, 0x00, 0xe1,
        0x00, 0x04, 0x00, 0x07, 0x00, 0x02, 0x00, 0xe3, 0x00, 0x02, 0x00, 0xea,
        0x00, 0x04, 0x00, 0x04, 0x00, 0x01, 0x00, 0xe6, 0x00, 0x01, 0x01, 0x43,
        0x00, 0x08, 0x01, 0x00, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00, 0xe1,
        0x00, 0x04, 0x00, 0x0c, 0x00, 0x04, 0x00, 0xe2, 0x00, 0x04, 0x00, 0x07,
        0x00, 0x02, 0x00, 0xe3, 0x00, 0x02, 0x00, 0x0b, 0x00, 0x02, 0x00, 0xe4,
        0x00, 0x02, 0x00, 0xea, 0x00, 0x04, 0x00, 0x04, 0x00, 0x01, 0x00, 0xe6,
        0x00, 0x01, 0x01, 0x43, 0x00, 0x08, 0x01, 0x00, 0x02, 0x18, 0x64, 0x40,
        0x9c, 0x93, 0xb9, 0x06, 0x19, 0x9c, 0x42, 0xdc, 0x98, 0x13, 0x42, 0xdc,
        0x98, 0x13, 0xd5, 0x40, 0x7b, 0xc8, 0x01, 0xbb, 0x01, 0xbb, 0x00, 0x00,
        0x00, 0x00, 0x06, 0x01, 0x00, 0x00, 0x01, 0x47, 0xa5, 0xe4, 0x92, 0xe5,
        0x64, 0x40, 0xa1, 0x19, 0xb9, 0x06, 0x19, 0xa1, 0x5b, 0xda, 0x7a, 0x94,
        0x5b, 0xda, 0x7a, 0x94, 0xcf, 0x6b, 0xdf, 0x60, 0x00, 0x50, 0x00, 0x50,
        0x00, 0x00, 0x00, 0x00, 0x06, 0x01, 0x00, 0x00, 0x01, 0x47, 0xa5, 0xe4,
        0x92, 0xe5, 0x64, 0x40, 0x31, 0x94, 0xb9, 0x06, 0x19, 0x31, 0x02, 0x85,
        0x7a, 0x86, 0x02, 0x85, 0x7a, 0x86, 0xce, 0xe4, 0xb6, 0x74, 0x1a, 0xe1,
        0x1a, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x06, 0x01, 0x00, 0x00, 0x01, 0x47,
        0xa5, 0xe4, 0x92, 0xe5, 0x64, 0x40, 0x31, 0x94, 0xb9, 0x06, 0x19, 0x31,
        0x5f, 0x98, 0x06, 0x43, 0x5f, 0x98, 0x06, 0x43, 0xce, 0xe2, 0xb6, 0x75,
        0x1a, 0xe2, 0x1a, 0xe2, 0x00, 0x00, 0x00, 0x00, 0x06, 0x01, 0x00, 0x00,
        0x01, 0x47, 0xa5, 0xe4, 0x92, 0xe5, 0x64, 0x40, 0xd9, 0x68, 0xb9, 0x06,
        0x19, 0xd9, 0xb9, 0x0c, 0xf1, 0x9b, 0xb9, 0x0c, 0xf1, 0x9b, 0x04, 0x19,
        0x78, 0xb0, 0x00, 0x50, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x06, 0x02,
        0x00, 0x00, 0x01, 0x47, 0xa5, 0xe4, 0x92, 0xe5, 0x64, 0x40, 0x31, 0x94,
        0xb9, 0x06, 0x19, 0x31, 0xb2, 0x2f, 0x7a, 0xa0, 0xb2, 0x2f, 0x7a, 0xa0,
        0xce, 0xe3, 0xb6, 0x76, 0x1a, 0xe1, 0x1a, 0xe1, 0x00, 0x00, 0x00, 0x00,
        0x06, 0x01, 0x00, 0x00, 0x01, 0x47, 0xa5, 0xe4, 0x92, 0xe6, 0x64, 0x40,
        0xc5, 0xc9, 0xb9, 0x06, 0x19, 0xc5, 0x57, 0xf0, 0xa2, 0x4f, 0x57, 0xf0,
        0xa2, 0x4f, 0xa0, 0x5d, 0x1a, 0xe0, 0x00, 0x50, 0x00, 0x50, 0x00, 0x00,
        0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 0x01, 0x47, 0xa5, 0xe4, 0x92, 0xe6,
        0x64, 0x40, 0x95, 0x02, 0xb9, 0x06, 0x19, 0x95, 0xb4, 0x04, 0x10, 0x79,
        0xb4, 0x04, 0x10, 0x79, 0x04, 0x43, 0x5a, 0x63, 0x2c, 0x79, 0x2c, 0x79,
        0x00, 0x00, 0x00, 0x00, 0x11, 0x01, 0x00, 0x00, 0x01, 0x47, 0xa5, 0xe4,
        0x92, 0xe6, 0x64, 0x40, 0x9a, 0x67, 0xb9, 0x06, 0x19, 0x9a, 0x57, 0xf0,
        0x87, 0xd2, 0x57, 0xf0, 0x87, 0xd2, 0xfc, 0x39, 0x3a, 0xc2, 0x00, 0x50,
        0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 0x01, 0x47,
        0xa5, 0xe4, 0x92, 0xe6, 0x64, 0x40, 0xf4, 0x3b, 0xb9, 0x06, 0x19, 0xf4,
        0xad, 0xc2, 0x20, 0x81, 0xad, 0xc2, 0x20, 0x81, 0xb2, 0x96, 0x5a, 0xc9,
        0x01, 0xbb, 0x01, 0xbb, 0x00, 0x00, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00,
        0x01, 0x47, 0xa5, 0xe4, 0x92, 0xe6, 0x64, 0x40, 0xb9, 0x26, 0xb9, 0x06,
        0x19, 0xb9, 0x56, 0x3b, 0xed, 0x27, 0x56, 0x3b, 0xed, 0x27, 0x51, 0xa8,
        0x69, 0x91, 0xc8, 0xd5, 0xc8, 0xd5, 0x00, 0x00, 0x00, 0x00, 0x11, 0x02,
        0x00, 0x00, 0x01, 0x47, 0xa5, 0xe4, 0x92, 0xe6, 0x64, 0x40, 0xc6, 0x2c,
        0xb9, 0x06, 0x19, 0xc6, 0xd9, 0x76, 0x5f, 0x41, 0xd9, 0x76, 0x5f, 0x41,
        0xd3, 0xf3, 0xd2, 0xce, 0x53, 0xb1, 0x53, 0xb1, 0x00, 0x00, 0x00, 0x00,
        0x06, 0x02, 0x00, 0x00, 0x01, 0x47, 0xa5, 0xe4, 0x92, 0xe6, 0x64, 0x40,
        0x52, 0xb2, 0xb9, 0x06, 0x19, 0x52, 0x57, 0xf5, 0xc4, 0x6a, 0x57, 0xf5,
        0xc4, 0x6a, 0x97, 0x94, 0x99, 0xa0, 0x00, 0x50, 0x00, 0x50, 0x00, 0x00,
        0x00, 0x00, 0x06, 0x01, 0x00, 0x00, 0x01, 0x47, 0xa5, 0xe4, 0x92, 0xe6,
        0x64, 0x40, 0x50, 0x95, 0xb9, 0x06, 0x19, 0x50, 0xbc, 0x2b, 0x6f, 0xa0,
        0xbc, 0x2b, 0x6f, 0xa0, 0xfb, 0xfb, 0x5c, 0x5c, 0x58, 0x7c, 0x58, 0x7c,
        0x00, 0x00, 0x00, 0x00, 0x06, 0x02, 0x00, 0x00, 0x01, 0x47, 0xa5, 0xe4,
        0x92, 0xe6
};
unsigned char cflow_cap_9_small[] = {
        0x00, 0x09,
        0x00, 0x02, 0x04, 0xb9, 0x94, 0x77, 0x61, 0xac, 0x69, 0x56, 0x00, 0x00, 0x1a, 0x21, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x0e, 0x00, 0x64, 0x00, 0x00, 0x0b, 0xb8, 0x00, 0x00, 0x00, 0x0a, 0x06, 0x00, 0xb1, 0x7a,
        0x01, 0xbb, 0x04, 0xc0, 0xa8, 0x01, 0x7e, 0xc0, 0xa8, 0x01, 0x28, 0x00, 0x02, 0x00, 0x05, 0x00, 0x00, 0xc0,
        0xa8, 0x00, 0x00, 0xc0, 0xa8, 0x00, 0x01, 0x01, 0x01, 0x02, 0x04, 0xb9, 0x93, 0x4b, 0x04, 0xb9, 0x94, 0x77,
        0x00, 0x00, 0x0b, 0xb8, 0x00, 0x00, 0x00, 0x0a, 0x06, 0x00, 0xb1, 0x7a, 0x01, 0xbb, 0x04, 0xc0, 0xa8, 0x01,
        0x28, 0xc0, 0xa8, 0x01, 0x36, 0x00, 0x03, 0x00, 0x06, 0x00, 0x00, 0xc0, 0xa8, 0x00, 0x00, 0xc0, 0xa8, 0x00,
        0x01, 0x01, 0x01, 0x02, 0x04, 0xb9, 0x93, 0x4b, 0x04, 0xb9, 0x94, 0x77
};

unsigned char cflow_cap_5[] = {
        0x00, 0x05,
        0x00, 0x0e, 0x00, 0xea, 0x1b, 0x43, 0x61, 0x8a, 0x21, 0x0b, 0x38, 0x23, 0xf6, 0xa8, 0x00, 0x28, 0x08, 0xee,
        0x01, 0x01, 0x00, 0x00, 0x0a, 0x00, 0x00, 0xc4, 0x14, 0x00, 0x00, 0x0f, 0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01,
        0x00, 0x02, 0x00, 0x00, 0x01, 0x0f, 0x00, 0x04, 0x38, 0x41, 0x00, 0xea, 0x19, 0x03, 0x00, 0xea, 0x1b, 0x43,
        0x06, 0xb1, 0x0e, 0x81, 0x00, 0x1b, 0x06, 0x00, 0x00, 0x67, 0x00, 0xcb, 0x18, 0x18, 0x00, 0x00, 0x0a, 0x00,
        0x00, 0xc5, 0x14, 0x00, 0x00, 0xce, 0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x9a,
        0x00, 0x03, 0x7a, 0x73, 0x00, 0xea, 0x18, 0xc0, 0x00, 0xea, 0x1b, 0x43, 0x06, 0xb2, 0x0e, 0x82, 0x00, 0x1b,
        0x06, 0x00, 0x00, 0x68, 0x00, 0xcc, 0x18, 0x18, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x18, 0x14, 0x00, 0x00, 0x73,
        0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x03, 0x48, 0x00, 0x00, 0x0a, 0xf4, 0x00, 0xea,
        0x18, 0x84, 0x00, 0xea, 0x1b, 0x43, 0x06, 0xb3, 0x0e, 0x83, 0x00, 0x1b, 0x06, 0x00, 0x00, 0x69, 0x00, 0xcd,
        0x18, 0x18, 0x00, 0x00, 0x0a, 0x00, 0x00, 0xe7, 0x14, 0x00, 0x00, 0x6b, 0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01,
        0x00, 0x02, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x02, 0xd1, 0xeb, 0x00, 0xea, 0x18, 0xaf, 0x00, 0xea, 0x1b, 0x43,
        0x06, 0xb4, 0x0e, 0x84, 0x00, 0x1b, 0x06, 0x00, 0x00, 0x6a, 0x00, 0xce, 0x18, 0x18, 0x00, 0x00, 0x0a, 0x00,
        0x00, 0x58, 0x14, 0x00, 0x00, 0xee, 0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x01, 0xde,
        0x00, 0x02, 0x60, 0xc4, 0x00, 0xea, 0x18, 0x98, 0x00, 0xea, 0x1b, 0x43, 0x06, 0xb5, 0x0e, 0x85, 0x00, 0x1b,
        0x06, 0x00, 0x00, 0x6b, 0x00, 0xcf, 0x18, 0x18, 0x00, 0x00, 0x0a, 0x00, 0x00, 0xc1, 0x14, 0x00, 0x00, 0x7f,
        0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x03, 0xc9, 0x00, 0x01, 0x24, 0x84, 0x00, 0xea,
        0x1a, 0x24, 0x00, 0xea, 0x1b, 0x43, 0x06, 0xb6, 0x0e, 0x86, 0x00, 0x1b, 0x06, 0x00, 0x00, 0x6c, 0x00, 0xd0,
        0x18, 0x18, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x06, 0x14, 0x00, 0x00, 0x06, 0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01,
        0x00, 0x02, 0x00, 0x00, 0x01, 0x56, 0x00, 0x01, 0x4f, 0x8c, 0x00, 0xea, 0x17, 0x95, 0x00, 0xea, 0x1b, 0x43,
        0x06, 0xb7, 0x0e, 0x87, 0x00, 0x1b, 0x06, 0x00, 0x00, 0x6d, 0x00, 0xd1, 0x18, 0x18, 0x00, 0x00, 0x0a, 0x00,
        0x00, 0xe6, 0x14, 0x00, 0x00, 0x11, 0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x02, 0xf4,
        0x00, 0x00, 0x3f, 0xe4, 0x00, 0xea, 0x18, 0x0a, 0x00, 0xea, 0x1b, 0x43, 0x06, 0xb8, 0x0e, 0x88, 0x00, 0x1b,
        0x06, 0x00, 0x00, 0x6e, 0x00, 0xd2, 0x18, 0x18, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x64, 0x14, 0x00, 0x00, 0x26,
        0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x01, 0x1c, 0x00, 0x01, 0x10, 0xe3, 0x00, 0xea,
        0x1a, 0x9f, 0x00, 0xea, 0x1b, 0x43, 0x06, 0xb9, 0x0e, 0x89, 0x00, 0x1b, 0x06, 0x00, 0x00, 0x65, 0x00, 0xc9,
        0x18, 0x18, 0x00, 0x00, 0x0a, 0x00, 0x00, 0xf8, 0x14, 0x00, 0x00, 0x25, 0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01,
        0x00, 0x02, 0x00, 0x00, 0x02, 0x43, 0x00, 0x04, 0x8d, 0xc1, 0x00, 0xea, 0x18, 0x4b, 0x00, 0xea, 0x1b, 0x43,
        0x06, 0xba, 0x0e, 0x8a, 0x00, 0x1b, 0x06, 0x00, 0x00, 0x66, 0x00, 0xca, 0x18, 0x18, 0x00, 0x00, 0x0a, 0x00,
        0x00, 0x3b, 0x14, 0x00, 0x00, 0x57, 0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x02, 0xbd,
        0x00, 0x03, 0x3b, 0xf7, 0x00, 0xea, 0x17, 0xe6, 0x00, 0xea, 0x1b, 0x43, 0x06, 0xbb, 0x0e, 0x8b, 0x00, 0x1b,
        0x06, 0x00, 0x00, 0x67, 0x00, 0xcb, 0x18, 0x18, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x60, 0x14, 0x00, 0x00, 0x76,
        0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x01, 0x6c, 0x00, 0x01, 0x98, 0x65, 0x00, 0xea,
        0x18, 0x76, 0x00, 0xea, 0x1b, 0x43, 0x06, 0xbc, 0x0e, 0x8c, 0x00, 0x1b, 0x06, 0x00, 0x00, 0x68, 0x00, 0xcc,
        0x18, 0x18, 0x00, 0x00, 0x0a, 0x00, 0x00, 0xa2, 0x14, 0x00, 0x00, 0x5e, 0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01,
        0x00, 0x02, 0x00, 0x00, 0x02, 0xe1, 0x00, 0x04, 0x75, 0x4e, 0x00, 0xea, 0x18, 0xb1, 0x00, 0xea, 0x1b, 0x43,
        0x06, 0xbd, 0x0e, 0x8d, 0x00, 0x1b, 0x06, 0x00, 0x00, 0x69, 0x00, 0xcd, 0x18, 0x18, 0x00, 0x00, 0x0a, 0x00,
        0x00, 0xac, 0x14, 0x00, 0x00, 0xdf, 0x1e, 0x00, 0x00, 0xfe, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x02, 0xd1,
        0x00, 0x01, 0xf8, 0x81, 0x00, 0xea, 0x17, 0x9c, 0x00, 0xea, 0x1b, 0x43, 0x06, 0xbe, 0x0e, 0x8e, 0x00, 0x1b,
        0x06, 0x00, 0x00, 0x6a, 0x00, 0xce, 0x18, 0x18, 0x00, 0x00

};


unsigned char cflow_cap_5_small[] = {
        0x00, 0x05,
        0x00, 0x01, 0x00, 0x60, 0x11, 0xe1, 0x61, 0xac, 0x65, 0x2f, 0x2e, 0x20, 0xf5, 0xc0, 0x00, 0x0b,
        0xe1, 0x9c, 0x01, 0x01, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x4f, 0x14, 0x00, 0x00, 0x67, 0x1e, 0x00, 0x00, 0xfe,
        0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x01, 0xdd, 0x00, 0x02, 0x2b, 0x4c, 0x00, 0x60, 0x11, 0x91, 0x00, 0x60,
        0x11, 0xe1, 0x06, 0x74, 0x0e, 0x44, 0x00, 0x1b, 0x06, 0x00, 0x00, 0x66, 0x00, 0xca, 0x18, 0x18, 0x00, 0x00
};

unsigned char cflow_cap_IPFIX[] = {
        0x00, 0x0a, 0x00, 0x72, 0x61, 0xac, 0x68, 0x19, 0x00, 0x00, 0x16, 0xa3, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06,
        0x00, 0x62, 0x00, 0x00, 0x0b, 0xb8, 0x00, 0x00, 0x00, 0x0a, 0x11, 0x00, 0x22, 0x34, 0x06, 0x43, 0x0a, 0x01,
        0x01, 0xa4, 0x14, 0x01, 0x01, 0x56, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x0a, 0x01, 0x00, 0x00, 0x14, 0x01,
        0x00, 0x01, 0x01, 0x01, 0x02, 0x04, 0xb4, 0xbe, 0x3b, 0x04, 0xb4, 0xbf, 0x67, 0x00, 0x00, 0x0b, 0xb8, 0x00,
        0x00, 0x00, 0x0a, 0x11, 0x00, 0x18, 0x34, 0x14, 0x5b, 0x0a, 0x01, 0x01, 0x59, 0x14, 0x01, 0x01, 0x7f, 0x00,
        0x06, 0x00, 0x05, 0x00, 0x00, 0x0a, 0x01, 0x00, 0x00, 0x14, 0x01, 0x00, 0x01, 0x01, 0x01, 0x02, 0x04, 0xb4,
        0xbe, 0x3b, 0x04, 0xb4, 0xbf, 0x67
};
unsigned char memcached_cap_get[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x67, 0x65, 0x74, 0x20,
        0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x31, 0x32,
//        0x77, 0x75, 0x70, 0x65, 0x6e, 0x67,
        0x0d, 0x0a
};

void Worker::Run() {

    int sd;
    struct sockaddr_in addr{};

    if ((sd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        safe_cout("Error: Creating socket.");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons((short) (size_t) port_);
    addr.sin_addr.s_addr = inet_addr(dest_);

    switch (netflow_version_) {
        case 5:
            while (true) {
                if (sendto(sd, &cflow_cap_5, sizeof(cflow_cap_5), 0,
                           (struct sockaddr *) &addr, sizeof(addr)) < 0) {
                    safe_cout("Error: Sent failed.");
                    exit(EXIT_FAILURE);
                }
                requests_->fetch_add(1);
                for (int i = 0; i < count_; i++) {}
            }
        case 6:
            while (true) {
                if (sendto(sd, &cflow_cap_5_small, sizeof(cflow_cap_5_small), 0,
                           (struct sockaddr *) &addr, sizeof(addr)) < 0) {
                    safe_cout("Error: Sent failed.");
                    exit(EXIT_FAILURE);
                }
                requests_->fetch_add(1);
                for (int i = 0; i < count_; i++) {}
            }
        case 8:
            while (true) {
                if (sendto(sd, &cflow_cap_9_small, sizeof(cflow_cap_9_small), 0,
                           (struct sockaddr *) &addr, sizeof(addr)) < 0) {
                    safe_cout("Error: Sent failed.");
                    exit(EXIT_FAILURE);
                }
                requests_->fetch_add(1);
                for (int i = 0; i < count_; i++) {}
            }
        case 9:
            while (true) {
                if (sendto(sd, &cflow_cap, sizeof(cflow_cap), 0,
                           (struct sockaddr *) &addr, sizeof(addr)) < 0) {
                    safe_cout("Error: Sent failed.");
                    exit(EXIT_FAILURE);
                }
                requests_->fetch_add(1);
                for (int i = 0; i < count_; i++) {}
            }
        case 10:
            while (true) {
                if (sendto(sd, &cflow_cap_IPFIX, sizeof(cflow_cap_IPFIX), 0,
                           (struct sockaddr *) &addr, sizeof(addr)) < 0) {
                    safe_cout("Error: Sent failed.");
                    exit(EXIT_FAILURE);
                }
                requests_->fetch_add(1);
                for (int i = 0; i < count_; i++) {}
            }
        case 1:
            while (true) {
                if (sendto(sd, &memcached_cap_get, sizeof(memcached_cap_get), 0,
                           (struct sockaddr *) &addr, sizeof(addr)) < 0) {
                    safe_cout("Error: Sent failed.");
                    exit(EXIT_FAILURE);
                }
                requests_->fetch_add(1);
                for (int i = 0; i < count_; i++) {}
            }
        default:
            safe_cout("Error: netflow version not specified.");
            exit(EXIT_FAILURE);
    }


    close(sd);

}

Worker::Worker(char *dest, u_short port, mutex *mtx, atomic_ulong *requests, u_short netflow_version, int count)
        : dest_(
        dest),
          port_(port),
          mtx_(mtx),
          requests_(
                  requests),
          netflow_version_(
                  netflow_version),
          count_(count) {}

void Worker::safe_cout(const string &msg) {
    lock_guard <mutex> lock(*mtx_);
    cout << msg;
}
