/***************************************************************************
 *   Copyright (C) 2012~2012 by CSSlayer                                   *
 *   wengxt@gmail.com                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef FCITX_KEYBOARD_H
#define FCITX_KEYBOARD_H

#include "config.h"

#include <iconv.h>

#ifdef ENCHANT_FOUND
#include <enchant/enchant.h>
#endif

#ifdef PRESAGE_FOUND
#include <presage.h>
#endif

#include <fcitx/ime.h>
#include <fcitx-utils/utarray.h>
#include <fcitx-config/fcitx-config.h>
#include "rules.h"

#define FCITX_KEYBOARD_MAX_BUFFER 20
#define FCITX_MAX_COMPOSE_LEN 7

typedef enum _EnchantProvider {
    EP_Default = 0,
    EP_Aspell = 1,
    EP_Myspell = 2
} EnchantProvider;

typedef struct _FcitxKeyboardConfig {
    FcitxGenericConfig gconfig;
    boolean bCommitWithExtraSpace;
    boolean bUseEnterToCommit;
    boolean bUsePresage;
    FcitxHotkey hkToggleWordHint[2];
    FcitxHotkey hkAddToUserDict[2];
    int minimumHintLength;
    EnchantProvider provider;
} FcitxKeyboardConfig;

typedef struct _FcitxKeyboard {
    struct _FcitxInstance* owner;
    char dictLang[6];
#ifdef ENCHANT_FOUND
    EnchantBroker* broker;
    UT_array* enchantLanguages;
    EnchantDict* dict;
#endif
    FcitxKeyboardConfig config;
    FcitxXkbRules* rules;
    iconv_t iconv;
    char* initialLayout;
    char* initialVariant;
#ifdef PRESAGE_FOUND
    presage_t presage;
#endif
    char buffer[FCITX_KEYBOARD_MAX_BUFFER + UTF8_MAX_LENGTH + 1];
    int cursorPos;
    uint composeBuffer[FCITX_MAX_COMPOSE_LEN + 1];
    int n_compose;
    char* tempBuffer;
    int lastLength;
    int dataSlot;
} FcitxKeyboard;

typedef struct _FcitxKeyboardLayout {
    FcitxKeyboard* owner;
    char* layoutString;
    char* variantString;
} FcitxKeyboardLayout;

CONFIG_BINDING_DECLARE(FcitxKeyboardConfig);

#endif
