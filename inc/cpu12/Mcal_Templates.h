/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
 *                                      cpu12.gems@googlemail.com>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * s. FLOSS-EXCEPTION.txt
 */
#if !defined(__MCAL_TEMPLATES_H)
#define __MCAL_TEMPLATES_H

/*
**  NOTE: This file is handcrafted, future versions will be generated.
*/

#include "mcu/s12/inc/S12_Atd.h"
#include "mcu/s12/inc/S12_Mebi.h"
#include "mcu/s12/inc/S12_Pim.h"
#include "mcu/s12/inc/S12_Spi.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
** todo: Must be configurable, we don't want to link unused Modules!!!
*/
#define DEFINE_DIO_FUNCTIONS()                  \
    const Dio_FunctionsType Dio_Functions[] = {       \
        {                                           \
            S12Mebi_WritePort,                      \
            S12Mebi_ReadPort,                       \
            S12Mebi_WriteChannel,                   \
            S12Mebi_ReadChannel,                    \
            S12Mebi_WriteChannelGroup,              \
            S12Mebi_ReadChannelGroup,               \
        },                                          \
        {                                           \
            S12Pim_WritePort,                       \
            S12Pim_ReadPort,                        \
            S12Pim_WriteChannel,                    \
            S12Pim_ReadChannel,                     \
            S12Pim_WriteChannelGroup,               \
            S12Pim_ReadChannelGroup,                \
        },                                          \
    }

#define DEFINE_DIO_PORT_TO_FUNCTIONS()                      \
    static const Dio_PortMappingType Dio_Ports_to_Functions[] =  \
    {                                                           \
        {0, S12MEBI_PORT_A},                                     \
        {0, S12MEBI_PORT_B},                                     \
        {0, S12MEBI_PORT_E},                                     \
        {0, S12MEBI_PORT_K},                                     \
        {1, S12PIM_PORT_T },                                      \
        {1, S12PIM_PORT_S },                                      \
        {1, S12PIM_PORT_M },                                      \
        {1, S12PIM_PORT_P },                                      \
        {1, S12PIM_PORT_H },                                      \
        {1, S12PIM_PORT_J },                                      \
    }

#define DIO_NUM_PORTS SIZEOF_ARRAY(Dio_Ports_to_Functions)

#define DEFINE_PORT_FUNCTIONS()             \
    const Port_FunctionsType Port_Functions[] = { \
        {                                       \
            S12Mebi_SetPinDirection,            \
        },                                      \
        {                                       \
            S12Pim_SetPinDirection,             \
        },                                      \
    }

#define DEFINE_PORT_PORT_TO_FUNCTIONS()                         \
    static const Port_PortMappingType Port_Ports_to_Functions[] =    \
    {                                                               \
        {0, S12MEBI_PORT_A},                                         \
        {0, S12MEBI_PORT_B},                                         \
        {0, S12MEBI_PORT_E},                                         \
        {0, S12MEBI_PORT_K},                                         \
        {1, S12PIM_PORT_T },                                          \
        {1, S12PIM_PORT_S },                                          \
        {1, S12PIM_PORT_M },                                          \
        {1, S12PIM_PORT_P },                                          \
        {1, S12PIM_PORT_H },                                          \
        {1, S12PIM_PORT_J },                                          \
    }

#define IMPLEMENT_PORT_INIT()                                   \
    _BEGIN_BLOCK                                                    \
    S12Mebi_Init(ConfigPtr->Mebi);                                  \
    S12Pim_Init(ConfigPtr->Pim);                                    \
    _END_BLOCK

#define IMPLEMENT_PORT_REFRESH_DIRECTION()                      \
    _BEGIN_BLOCK                                                    \
    S12Pim_RefreshPortDirection(Port_ConfigurationPtr->Pim);        \
    S12Mebi_RefreshPortDirection(Port_ConfigurationPtr->Mebi);      \
    _END_BLOCK

#define IMPLEMENT_PORT_SET_MODE()                               \
    _BEGIN_BLOCK                                                    \
    UNREFERENCED_PARAMETER(Pin);                                    \
    UNREFERENCED_PARAMETER(Mode);                                   \
    _END_BLOCK

/*
**  SPI.
*/
#define IMPLEMENT_SPI_INIT()                                    \
    _BEGIN_BLOCK                                                    \
    S12Spi_Init(ConfigPtr->Cfg);                                    \
    _END_BLOCK

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __MCAL_TEMPLATES_H */
