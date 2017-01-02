-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jan 02, 2017 at 03:18 PM
-- Server version: 5.6.17
-- PHP Version: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `test`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE IF NOT EXISTS `admin` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `loginid` varchar(50) NOT NULL,
  `pass` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`id`, `loginid`, `pass`) VALUES
(1, 'Jagat', 'jagat'),
(2, 'admin', 'admin');

-- --------------------------------------------------------

--
-- Table structure for table `questions_type1`
--

CREATE TABLE IF NOT EXISTS `questions_type1` (
  `qno` int(11) NOT NULL AUTO_INCREMENT,
  `ques` varchar(1000) NOT NULL,
  `code` varchar(1000) DEFAULT NULL,
  `opta` varchar(1000) NOT NULL,
  `optb` varchar(1000) NOT NULL,
  `optc` varchar(1000) NOT NULL,
  `optd` varchar(1000) NOT NULL,
  `optright` char(1) NOT NULL,
  PRIMARY KEY (`qno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `teaminfo`
--

CREATE TABLE IF NOT EXISTS `teaminfo` (
  `name` varchar(8) NOT NULL,
  `college` varchar(50) NOT NULL,
  `ns` tinyint(1) NOT NULL,
  `name1` varchar(50) NOT NULL,
  `usn1` varchar(12) NOT NULL,
  `email1` varchar(50) NOT NULL,
  `phone1` varchar(10) NOT NULL,
  `name2` varchar(50) DEFAULT NULL,
  `usn2` varchar(12) DEFAULT NULL,
  `email2` varchar(50) DEFAULT NULL,
  `phone2` varchar(10) DEFAULT NULL,
  `score` float(5,2) NOT NULL,
  `time` int(11) DEFAULT NULL,
  `ipaddress` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`name`),
  UNIQUE KEY `usn1` (`usn1`,`phone1`,`usn2`,`phone2`),
  UNIQUE KEY `usn2unique` (`usn2`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
