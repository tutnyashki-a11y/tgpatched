/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include <QString>

// Порт v2 (Менеджер аккаунтов): профиль запуска из workdir.
// Заполняется в core/application.cpp (ApplyWorkdirProxy) ТОЛЬКО после
// проверки Ed25519-подписи запуска; без валидного токена все геттеры
// возвращают пустые строки, и клиент работает со своими реальными данными.
namespace Workdir {

// Имя аккаунта (account_name.txt) — дописывается к заголовку окна.
[[nodiscard]] QString AccountLabel();

// Суффикс заголовка окна: " — <имя аккаунта>" либо пустая строка.
[[nodiscard]] QString TitleSuffix();

// Переопределение отпечатка устройства (device.txt: model / system / app).
[[nodiscard]] QString DeviceModel();
[[nodiscard]] QString SystemVersion();
[[nodiscard]] QString AppVersion();

} // namespace Workdir
