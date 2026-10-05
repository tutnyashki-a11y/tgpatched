/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include <cstdint>
#include <QString>

// Порт v2 (Менеджер аккаунтов): профиль запуска из workdir.
// Заполняется в core/application.cpp (ApplyWorkdirProxy) ТОЛЬКО после
// проверки Ed25519-подписи запуска; без валидного токена все геттеры
// возвращают пустые строки / Gated() == false, и клиент работает
// как обычный Telegram.
namespace Workdir {

// Имя аккаунта (account_name.txt) — дописывается к заголовку окна.
[[nodiscard]] QString AccountLabel();

// Суффикс заголовка: " — <имя аккаунта>" + " (без сети)" при отсутствии
// соединения. Пустая строка, если нечего показывать.
[[nodiscard]] QString TitleSuffix();

// Переопределение отпечатка устройства (device.txt: model / system / app).
[[nodiscard]] QString DeviceModel();
[[nodiscard]] QString SystemVersion();
[[nodiscard]] QString AppVersion();

// Лицензионный запуск (подпись проверена) — гейт для блокировок UI
// (настройки прокси, добавление/удаление аккаунтов).
[[nodiscard]] bool Gated();

// Инициализация профиля из workdir. Вызывается ТОЛЬКО из application.cpp
// после проверки Ed25519-подписи запуска.
void InitProfile(const QString &workdir);

// Состояние сети последнего опроса (true = не подключено).
[[nodiscard]] bool Offline();
void SetOffline(bool offline);

// Путь workdir процесса (пуст вне лицензионного запуска).
[[nodiscard]] QString WorkdirPath();

// Обновить состояние сети из dcstate(). Пишет status.txt в workdir при
// изменении. Возвращает true, если состояние изменилось (обновить заголовок).
[[nodiscard]] bool UpdateConnectionState(int32_t dcState);

} // namespace Workdir
