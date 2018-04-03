-- phpMyAdmin SQL Dump
-- version 4.7.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 03, 2018 at 09:37 PM
-- Server version: 10.1.26-MariaDB
-- PHP Version: 7.1.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `stis`
--

-- --------------------------------------------------------

--
-- Table structure for table `bus`
--

CREATE TABLE `bus` (
  `bus_id` int(11) NOT NULL,
  `curr_latitude` double NOT NULL,
  `curr_longitude` double NOT NULL,
  `speed` float NOT NULL,
  `people_count` int(11) NOT NULL,
  `distance` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `bus`
--

INSERT INTO `bus` (`bus_id`, `curr_latitude`, `curr_longitude`, `speed`, `people_count`, `distance`) VALUES
(1, 21.2, 20, 2, 1, 2);

-- --------------------------------------------------------

--
-- Table structure for table `distance_to_stops`
--

CREATE TABLE `distance_to_stops` (
  `bus_id` int(11) NOT NULL,
  `VIT` double NOT NULL,
  `Kandigai` double NOT NULL,
  `Vandalur` double NOT NULL,
  `Perungalathur` double NOT NULL,
  `Tambaram` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `bus`
--
ALTER TABLE `bus`
  ADD PRIMARY KEY (`bus_id`);

--
-- Indexes for table `distance_to_stops`
--
ALTER TABLE `distance_to_stops`
  ADD PRIMARY KEY (`bus_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
