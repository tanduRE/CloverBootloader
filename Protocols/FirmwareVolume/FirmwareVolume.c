//
//  FirmwareVolume.c
//  Clover
//
//  Created by Slice on 19.10.16.
//

#include <Library/UefiLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include <EfiImageFormat.h>
#include <Protocol/FirmwareVolume.h>

EFI_HANDLE              mHandle = NULL;

EFI_GUID gAppleCursorImageGuid =  {0x1A10742F, 0xFA80, 0x4B79, {0x9D, 0xA6, 0x35, 0x70, 0x58, 0xCC, 0x39, 0x7B}};

UINT8 mAppleCursorImage[2428] = {
  0x42, 0x4D, 0x7A, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7A, 0x00, 0x00, 0x00, 0x6C, 0x00,
  0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0xE8, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x20, 0x00, 0x03, 0x00,
  0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
  0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x03, 0x00, 0x00, 0x00, 0x0B, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xDF, 0xDF, 0x5F, 0x00, 0x00,
  0x00, 0x09, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x07, 0x00, 0x00, 0x00, 0x19, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0xBF,
  0xBF, 0x54, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x09, 0x00, 0x00, 0x00, 0x23, 0xFF, 0xFF, 0xFF, 0xFF, 0x2A, 0x2A, 0x2A, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFE, 0xBF, 0xBF, 0xBF, 0x54, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
  0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x27, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x2A, 0x2A,
  0x2A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xBF, 0xBF, 0xBF, 0x54, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00,
  0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x28, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0xFF, 0x2A, 0x2A, 0x2A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xBF, 0xBF, 0xBF, 0x54, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x28, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x2A, 0x2A, 0x2A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xBF, 0xBF,
  0xBF, 0x54, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x28, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x2A, 0x2A, 0x2A, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFE, 0xBF, 0xBF, 0xBF, 0x54, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
  0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x28, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x2A, 0x2A,
  0x2A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xBF, 0xBF, 0xBF, 0x54, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00,
  0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x28, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0xFF, 0x2A, 0x2A, 0x2A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xBF, 0xBF, 0xBF, 0x54, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x28, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x2A, 0x2A, 0x2A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xC5, 0xC5,
  0xC5, 0x53, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x28, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
  0x00, 0xFF, 0x2A, 0x2A, 0x2A, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x2A, 0x2A, 0x2A, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF,
  0xFF, 0xFE, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x28, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0xFF, 0x2A, 0x2A,
  0x2A, 0xFF, 0xCF, 0xCF, 0xCF, 0xD4, 0x2A, 0x2A, 0x2A, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x8A, 0x8A,
  0x8A, 0xE0, 0xA6, 0xA6, 0xA6, 0xAB, 0x00, 0x00, 0x00, 0x5B, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00,
  0x00, 0x2F, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x28, 0xFF, 0xFF, 0xFF, 0xFE, 0x2A, 0x2A, 0x2A, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFE, 0xA4, 0xA4, 0xA4, 0xAD, 0x89, 0x89, 0x89, 0xDF, 0x00, 0x00, 0x00, 0xFF, 0x2A, 0x2A,
  0x2A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00,
  0x00, 0x19, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x0A, 0x00, 0x00, 0x00, 0x27, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00,
  0x00, 0x5A, 0x00, 0x00, 0x00, 0x55, 0xFF, 0xFF, 0xFF, 0xFE, 0x2A, 0x2A, 0x2A, 0xFF, 0x00, 0x00,
  0x00, 0xFF, 0x8E, 0x8E, 0x8E, 0xD9, 0xCC, 0xCC, 0xCC, 0x8B, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00,
  0x00, 0x09, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x09, 0x00, 0x00, 0x00, 0x22, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00,
  0x00, 0x38, 0x00, 0x00, 0x00, 0x38, 0xB6, 0xB6, 0xB6, 0x9D, 0x8B, 0x8B, 0x8B, 0xDE, 0x00, 0x00,
  0x00, 0xFF, 0x2A, 0x2A, 0x2A, 0xFF, 0xE7, 0xE7, 0xE7, 0xBF, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00,
  0x00, 0x05, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x07, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00,
  0x00, 0x19, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x3C, 0xFF, 0xFF, 0xFF, 0xFE, 0x2A, 0x2A,
  0x2A, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00,
  0x00, 0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x03, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x28, 0xB7, 0xB7, 0xB7, 0x9B, 0xFF, 0xFF,
  0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xBD, 0xBD, 0xBD, 0x96, 0x00, 0x00, 0x00, 0x1D, 0x00, 0x00,
  0x00, 0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
  0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00,
  0x00, 0x48, 0x00, 0x00, 0x00, 0x47, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00,
  0x00, 0x05, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00,
  0x00, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00,
  0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
  0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFD, 0xFD
};

EFI_STATUS
EFIAPI
FvGetVolumeAttributes (
                       IN  EFI_FIRMWARE_VOLUME_PROTOCOL  *This,
                       OUT FRAMEWORK_EFI_FV_ATTRIBUTES   *Attributes
                       )
{
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
FvSetVolumeAttributes (
                       IN EFI_FIRMWARE_VOLUME_PROTOCOL     *This,
                       IN OUT FRAMEWORK_EFI_FV_ATTRIBUTES  *Attributes
                       )
{
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
FvReadFile (
            IN EFI_FIRMWARE_VOLUME_PROTOCOL   *This,
            IN EFI_GUID                       *NameGuid,
            IN OUT VOID                       **Buffer,
            IN OUT UINTN                      *BufferSize,
            OUT EFI_FV_FILETYPE               *FoundType,
            OUT EFI_FV_FILE_ATTRIBUTES        *FileAttributes,
            OUT UINT32                        *AuthenticationStatus
            )
{
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
FvReadSection (
               IN EFI_FIRMWARE_VOLUME_PROTOCOL   *This,
               IN EFI_GUID                       *NameGuid,
               IN EFI_SECTION_TYPE               SectionType,
               IN UINTN                          SectionInstance,
               IN OUT VOID                       **Buffer,
               IN OUT UINTN                      *BufferSize,
               OUT UINT32                        *AuthenticationStatus
               )
{
  EFI_STATUS Status;
  
  if (!Buffer || !BufferSize) {
    return EFI_INVALID_PARAMETER;
  }
  if(CompareGuid (NameGuid, &gAppleCursorImageGuid)) {
    *BufferSize = sizeof(mAppleCursorImage);
    Status = gBS->AllocatePool(EfiBootServicesData, *BufferSize, (VOID **)Buffer);
    if (!EFI_ERROR(Status)) {
      gBS->CopyMem(*Buffer, &mAppleCursorImage, *BufferSize);
    } 
  }
  return Status;
}

EFI_STATUS
EFIAPI
FvWriteFile (
             IN EFI_FIRMWARE_VOLUME_PROTOCOL      *This,
             IN UINT32                            NumberOfFiles,
             IN FRAMEWORK_EFI_FV_WRITE_POLICY     WritePolicy,
             IN FRAMEWORK_EFI_FV_WRITE_FILE_DATA  *FileData
             )
{
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
FvGetNextFile (
               IN EFI_FIRMWARE_VOLUME_PROTOCOL   *This,
               IN OUT VOID                       *Key,
               IN OUT EFI_FV_FILETYPE            *FileType,
               OUT EFI_GUID                      *NameGuid,
               OUT EFI_FV_FILE_ATTRIBUTES        *Attributes,
               OUT UINTN                         *Size
               )
{
  return EFI_SUCCESS;
}

EFI_FIRMWARE_VOLUME_PROTOCOL   FirmwareVolume = {
  FvGetVolumeAttributes,
  FvSetVolumeAttributes,
  FvReadFile,
  FvReadSection,
  FvWriteFile,
  FvGetNextFile,
  16,    //KeySize
  NULL  //ParentHandle
};

/****************************************************************
 * Entry point
 ***************************************************************/

/**
 * FirmwareVolume entry point. Installs AppleGraphConfigProtocol.
 */
EFI_STATUS
EFIAPI
FVEntrypoint (IN EFI_HANDLE           ImageHandle,
              IN EFI_SYSTEM_TABLE		*SystemTable
              )
{
  EFI_STATUS					Status; 
  EFI_BOOT_SERVICES*			gBS;
  gBS				= SystemTable->BootServices;
  
  Status = gBS->InstallMultipleProtocolInterfaces (
                                                   &mHandle,
                                                   &gEfiFirmwareVolumeProtocolGuid,
                                                   &FirmwareVolume,
                                                   NULL
                                                   );
  
  return Status;
}

