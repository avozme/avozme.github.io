-- phpMyAdmin SQL Dump
-- version 4.9.5deb2
-- https://www.phpmyadmin.net/
--
-- Servidor: localhost:3306
-- Tiempo de generación: 05-10-2021 a las 14:36:33
-- Versión del servidor: 10.3.31-MariaDB-0ubuntu0.20.04.1
-- Versión de PHP: 7.4.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `acl`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `permissions`
--

CREATE TABLE `permissions` (
  `id` int(11) NOT NULL,
  `description` varchar(500) COLLATE utf8mb4_spanish_ci NOT NULL,
  `action` varchar(500) COLLATE utf8mb4_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `permissions`
--

INSERT INTO `permissions` (`id`, `description`, `action`) VALUES
(1, 'Crear contenido nuevo', 'createNewContentForm'),
(2, 'Editar contenido propio', 'editMyContentForm'),
(3, 'Editar contenido ajeno', 'editAnyContentForm'),
(4, 'Borrar contenido propio', 'deleteMyContent'),
(5, 'Borrar contenido ajeno', 'deleteAnyContent'),
(6, 'Publicar contenido propio', 'publishMyContentForm'),
(7, 'Publicar cualquier contenido', 'publishAnyContentForm'),
(8, 'Leer contenido', 'viewContent');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `permissions-roles`
--

CREATE TABLE `permissions-roles` (
  `idPermission` int(11) NOT NULL,
  `idRol` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `permissions-roles`
--

INSERT INTO `permissions-roles` (`idPermission`, `idRol`) VALUES
(1, 1),
(1, 2),
(2, 1),
(2, 2),
(3, 1),
(4, 1),
(5, 1),
(6, 1),
(6, 2),
(7, 1),
(8, 1),
(8, 2),
(8, 3);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `roles`
--

CREATE TABLE `roles` (
  `id` int(11) NOT NULL,
  `description` varchar(500) COLLATE utf8mb4_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `roles`
--

INSERT INTO `roles` (`id`, `description`) VALUES
(1, 'administrador'),
(2, 'editor'),
(3, 'usuario');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `roles-users`
--

CREATE TABLE `roles-users` (
  `idRol` int(11) NOT NULL,
  `idUser` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `roles-users`
--

INSERT INTO `roles-users` (`idRol`, `idUser`) VALUES
(1, 2),
(2, 1),
(2, 2);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `email` varchar(500) COLLATE utf8mb4_spanish_ci NOT NULL,
  `password` varchar(500) COLLATE utf8mb4_spanish_ci NOT NULL,
  `photo` varchar(500) COLLATE utf8mb4_spanish_ci NOT NULL,
  `name` varchar(500) COLLATE utf8mb4_spanish_ci NOT NULL,
  `phone` varchar(20) COLLATE utf8mb4_spanish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_spanish_ci;

--
-- Volcado de datos para la tabla `users`
--

INSERT INTO `users` (`id`, `email`, `password`, `photo`, `name`, `phone`) VALUES
(1, 'pepe@iescelia.org', '1234', 'tioguapo.jpg', 'Pepe Ibáñez', '555 109 115'),
(2, 'ana@iescelia.org', '1234', 'tiaguapa.jpg', 'Ana López', '555 989 231');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `permissions`
--
ALTER TABLE `permissions`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `permissions-roles`
--
ALTER TABLE `permissions-roles`
  ADD PRIMARY KEY (`idPermission`,`idRol`);

--
-- Indices de la tabla `roles`
--
ALTER TABLE `roles`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `roles-users`
--
ALTER TABLE `roles-users`
  ADD PRIMARY KEY (`idRol`,`idUser`);

--
-- Indices de la tabla `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `permissions`
--
ALTER TABLE `permissions`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT de la tabla `roles`
--
ALTER TABLE `roles`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT de la tabla `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
