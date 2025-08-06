-- phpMyAdmin SQL Dump
-- version 5.2.2deb1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Tempo de geração: 05/08/2025 às 13:34
-- Versão do servidor: 11.8.2-MariaDB-1 from Debian
-- Versão do PHP: 8.4.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `gtk4appdata`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `book_store`
--

CREATE TABLE `book_store` (
  `book_id` int(11) NOT NULL,
  `title` varchar(50) DEFAULT NULL,
  `author` varchar(50) DEFAULT NULL,
  `genre` varchar(50) DEFAULT NULL,
  `publication_date` varchar(50) DEFAULT NULL,
  `isbn` varchar(50) DEFAULT NULL,
  `price` varchar(50) DEFAULT NULL,
  `rating` decimal(2,1) DEFAULT NULL,
  `publisher` varchar(50) DEFAULT NULL,
  `language` varchar(50) DEFAULT NULL,
  `page_count` int(11) DEFAULT NULL,
  `created_at` datetime DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_uca1400_ai_ci;

--
-- Despejando dados para a tabela `book_store`
--

INSERT INTO `book_store` (`book_id`, `title`, `author`, `genre`, `publication_date`, `isbn`, `price`, `rating`, `publisher`, `language`, `page_count`, `created_at`) VALUES
(1, 'Honorable', 'Avrom MacGilrewy', 'Romance', '0000-00-00', '868147014-0', 'Dollar', 0.0, 'Yakitri', 'Galician', 282, '2025-08-05 10:32:45'),
(2, 'Dr', 'Catarina Drewet', 'Romance', '0000-00-00', '850504205-0', 'Boliviano', 0.9, 'Skidoo', 'Luxembourgish', 968, '2025-08-05 10:32:45'),
(3, 'Honorable', 'Milzie Lummis', 'Mystery', '0000-00-00', '657549557-5', 'Yuan Renminbi', 0.5, 'Yakitri', 'Dutch', 152, '2025-08-05 10:32:45'),
(4, 'Mrs', 'Garland Gaddes', 'Science Fiction', '0000-00-00', '365198918-6', 'Peso', 1.2, 'Feednation', 'Korean', 136, '2025-08-05 10:32:45'),
(5, 'Dr', 'Rutherford Sacco', 'Mystery', '0000-00-00', '872091186-6', 'Real', 2.5, 'Tekfly', 'Azerbaijani', 975, '2025-08-05 10:32:45'),
(6, 'Ms', 'Willabella Zorzin', 'Science Fiction', '0000-00-00', '637790982-9', 'Real', 0.6, 'Tazzy', 'Ossetian', 366, '2025-08-05 10:32:45'),
(7, 'Dr', 'Donny Story', 'Science Fiction', '0000-00-00', '139803447-9', 'Peso', 1.5, 'Talane', 'Volapük', 60, '2025-08-05 10:32:45'),
(8, 'Rev', 'Meg Biskupek', 'Romance', '0000-00-00', '660071487-5', 'Ringgit', 3.8, 'Voolith', 'Corsican', 208, '2025-08-05 10:32:45'),
(9, 'Ms', 'Dalis Pelman', 'Mystery', '0000-00-00', '475967792-5', 'Euro', 2.2, 'Roombo', 'Azerbaijani', 856, '2025-08-05 10:32:45'),
(10, 'Mr', 'Meggie D\'Angeli', 'Mystery', '0000-00-00', '134122601-8', 'Franc', 3.5, 'Miboo', 'Lingala', 977, '2025-08-05 10:32:45'),
(11, 'Ms', 'Nikki Dargie', 'Thriller', '0000-00-00', '993982928-0', 'Yuan Renminbi', 3.9, 'Innotype', 'Tagalog', 743, '2025-08-05 10:32:45'),
(12, 'Rev', 'Horst Judson', 'Mystery', '0000-00-00', '165793885-9', 'Euro', 3.8, 'Fivechat', 'Finnish', 317, '2025-08-05 10:32:45'),
(13, 'Mr', 'Rockie Banat', 'Science Fiction', '0000-00-00', '984466608-2', 'Zloty', 0.0, 'Feedbug', 'Thai', 6, '2025-08-05 10:32:45'),
(14, 'Ms', 'Tabb Skitteral', 'Fantasy', '0000-00-00', '285942532-2', 'Yuan Renminbi', 2.7, 'Thoughtblab', 'Aymara', 216, '2025-08-05 10:32:45'),
(15, 'Rev', 'Ortensia Geater', 'Fantasy', '0000-00-00', '343108696-9', 'Dollar', 4.8, 'Topdrive', 'Latvian', 709, '2025-08-05 10:32:45'),
(16, 'Honorable', 'Lara Heikkinen', 'Thriller', '0000-00-00', '919742460-9', 'Ruble', 4.9, 'Yotz', 'Italian', 418, '2025-08-05 10:32:45'),
(17, 'Ms', 'Dillon Dewerson', 'Romance', '0000-00-00', '460940376-5', 'Euro', 1.1, 'Realcube', 'Ganda', 395, '2025-08-05 10:32:45'),
(18, 'Ms', 'Harold Clerk', 'Romance', '0000-00-00', '082729439-5', 'Real', 3.8, 'Kanoodle', 'Malayalam', 733, '2025-08-05 10:32:45'),
(19, 'Honorable', 'Otis Frango', 'Romance', '0000-00-00', '434768421-5', 'Rupiah', 3.9, 'Camimbo', 'Italian', 780, '2025-08-05 10:32:45'),
(20, 'Rev', 'Joye Creamer', 'Thriller', '0000-00-00', '370844077-3', 'Dinar', 2.4, 'Mynte', 'Zulu', 584, '2025-08-05 10:32:45'),
(21, 'Honorable', 'Blakelee Holley', 'Thriller', '0000-00-00', '495857966-4', 'Ruble', 3.3, 'Chatterpoint', 'Oromo', 369, '2025-08-05 10:32:45'),
(22, 'Mr', 'Concordia Welsh', 'Fantasy', '0000-00-00', '422965426-X', 'Koruna', 4.1, 'Wikizz', 'Luxembourgish', 735, '2025-08-05 10:32:45'),
(23, 'Mr', 'Artie Yu', 'Thriller', '0000-00-00', '159479631-9', 'Hryvnia', 0.1, 'Livefish', 'Russian', 965, '2025-08-05 10:32:45'),
(24, 'Dr', 'Brewer Prettyjohn', 'Mystery', '0000-00-00', '220412753-1', 'Euro', 2.1, 'Realbuzz', 'Thai', 495, '2025-08-05 10:32:45'),
(25, 'Rev', 'Ardith Conklin', 'Science Fiction', '0000-00-00', '207526253-5', 'Leone', 0.4, 'Meemm', 'Afar', 862, '2025-08-05 10:32:45'),
(26, 'Mrs', 'Lolita Rodson', 'Science Fiction', '0000-00-00', '979513523-6', 'Euro', 2.1, 'Yakijo', 'Fulah', 29, '2025-08-05 10:32:45'),
(27, 'Dr', 'Sallie McClements', 'Thriller', '0000-00-00', '885753536-3', 'Rial', 2.3, 'Yakitri', 'Tamil', 600, '2025-08-05 10:32:45'),
(28, 'Rev', 'Levon Boffin', 'Fantasy', '0000-00-00', '609369817-3', 'Rupiah', 1.1, 'Devpoint', 'Ojibwa', 175, '2025-08-05 10:32:45'),
(29, 'Honorable', 'Lian Kierans', 'Fantasy', '0000-00-00', '259470523-3', 'Peso', 1.6, 'Roombo', 'Inupiaq', 986, '2025-08-05 10:32:45'),
(30, 'Mrs', 'Reynard Thomas', 'Thriller', '0000-00-00', '526532614-6', 'Rupiah', 3.7, 'Dablist', 'Tsonga', 364, '2025-08-05 10:32:45'),
(31, 'Ms', 'Jacinthe Critch', 'Science Fiction', '0000-00-00', '249814110-3', 'Ruble', 1.1, 'Miboo', 'Hebrew', 757, '2025-08-05 10:32:45'),
(32, 'Mr', 'Karoline O\'Calleran', 'Science Fiction', '0000-00-00', '350827813-1', 'Rupiah', 4.8, 'Demizz', 'Samoan', 7, '2025-08-05 10:32:45'),
(33, 'Dr', 'Derrick Gebuhr', 'Fantasy', '0000-00-00', '374897729-8', 'Ruble', 2.2, 'Ntags', 'Rundi', 99, '2025-08-05 10:32:45'),
(34, 'Ms', 'Sibyl Vasyutochkin', 'Fantasy', '0000-00-00', '708447124-3', 'Rupiah', 2.2, 'Ooba', 'Dutch', 735, '2025-08-05 10:32:45'),
(35, 'Rev', 'Rochella Gumey', 'Science Fiction', '0000-00-00', '129981575-8', 'Peso', 1.5, 'Tagpad', 'Vietnamese', 307, '2025-08-05 10:32:45'),
(36, 'Mr', 'Harlie Queyos', 'Romance', '0000-00-00', '683025133-8', 'Rial', 2.3, 'Kayveo', 'German', 857, '2025-08-05 10:32:45'),
(37, 'Mrs', 'Morten Larsen', 'Fantasy', '0000-00-00', '156009324-2', 'Euro', 2.3, 'Wikibox', 'Tigrinya', 388, '2025-08-05 10:32:45'),
(38, 'Dr', 'Claudina Seilmann', 'Mystery', '0000-00-00', '012161901-X', 'Koruna', 4.8, 'Feedspan', 'Greek, Modern (1453-)', 421, '2025-08-05 10:32:45'),
(39, 'Honorable', 'Cherilynn Haglington', 'Fantasy', '0000-00-00', '995396881-0', 'Naira', 4.3, 'Digitube', 'Tamil', 172, '2025-08-05 10:32:45'),
(40, 'Mrs', 'Arin Yurasov', 'Romance', '0000-00-00', '946519284-8', 'Yuan Renminbi', 3.8, 'Blogspan', 'Polish', 467, '2025-08-05 10:32:45'),
(41, 'Rev', 'Bobby Oldacres', 'Romance', '0000-00-00', '677205542-X', 'Euro', 4.4, 'Avavee', 'Kanuri', 469, '2025-08-05 10:32:45'),
(42, 'Rev', 'Romy Headingham', 'Mystery', '0000-00-00', '062320401-0', 'Shekel', 3.1, 'Yombu', 'Northern Sami', 787, '2025-08-05 10:32:45'),
(43, 'Ms', 'Mariana Attow', 'Mystery', '0000-00-00', '707798666-7', 'Peso', 4.8, 'Einti', 'Luxembourgish', 186, '2025-08-05 10:32:45'),
(44, 'Rev', 'Theadora Haynes', 'Science Fiction', '0000-00-00', '386667977-7', 'Real', 2.1, 'Gabtype', 'Gujarati', 689, '2025-08-05 10:32:45'),
(45, 'Rev', 'Olive Mileham', 'Mystery', '0000-00-00', '471904785-8', 'Yuan Renminbi', 1.7, 'Eabox', 'Twi', 458, '2025-08-05 10:32:45'),
(46, 'Rev', 'Vinita Ipwell', 'Thriller', '0000-00-00', '119760099-X', 'Franc', 5.0, 'Gigaclub', 'Tsonga', 734, '2025-08-05 10:32:45'),
(47, 'Honorable', 'Berkly Lathleiff', 'Fantasy', '0000-00-00', '837600603-7', 'Sol', 0.9, 'Quinu', 'Akan', 635, '2025-08-05 10:32:45'),
(48, 'Ms', 'Reeta Halbeard', 'Mystery', '0000-00-00', '091484028-2', 'Yuan Renminbi', 5.0, 'Mycat', 'Sardinian', 644, '2025-08-05 10:32:45'),
(49, 'Dr', 'Rebe Yeliashev', 'Fantasy', '0000-00-00', '617982366-9', 'Kwacha', 3.0, 'Edgetag', 'Guarani', 695, '2025-08-05 10:32:45'),
(50, 'Mr', 'Eduard Hannis', 'Fantasy', '0000-00-00', '564544263-6', 'Franc', 0.1, 'Vinder', 'Bulgarian', 422, '2025-08-05 10:32:45'),
(51, 'Honorable', 'Elspeth Jellico', 'Thriller', '0000-00-00', '001056659-7', 'Yuan Renminbi', 3.9, 'Brainlounge', 'Sango', 941, '2025-08-05 10:32:45'),
(52, 'Mr', 'Art Primmer', 'Thriller', '0000-00-00', '561013616-4', 'Yuan Renminbi', 1.9, 'Yadel', 'Icelandic', 280, '2025-08-05 10:32:45'),
(53, 'Ms', 'Debera McAndie', 'Fantasy', '0000-00-00', '639951330-8', 'Ruble', 4.1, 'Wikizz', 'Komi', 107, '2025-08-05 10:32:45'),
(54, 'Honorable', 'Alyss Mundle', 'Mystery', '0000-00-00', '940224612-6', 'Peso', 0.5, 'Meedoo', 'Uzbek', 455, '2025-08-05 10:32:45'),
(55, 'Dr', 'Rozina Bleby', 'Science Fiction', '0000-00-00', '627468991-5', 'Dram', 2.1, 'Kazio', 'Zulu', 477, '2025-08-05 10:32:45'),
(56, 'Honorable', 'Kennith Le Claire', 'Romance', '0000-00-00', '472109951-7', 'Peso', 4.7, 'Quire', 'Belarusian', 763, '2025-08-05 10:32:45'),
(57, 'Rev', 'Rutherford Matteo', 'Science Fiction', '0000-00-00', '599157103-1', 'Ruble', 3.3, 'Yambee', 'Ganda', 238, '2025-08-05 10:32:45'),
(58, 'Rev', 'Vernen Milillo', 'Fantasy', '0000-00-00', '399202155-6', 'Shekel', 0.2, 'Quinu', 'Avestan', 756, '2025-08-05 10:32:45'),
(59, 'Ms', 'Gerardo Gouinlock', 'Thriller', '0000-00-00', '437054421-1', 'Ruble', 1.8, 'Babbleblab', 'Venda', 387, '2025-08-05 10:32:45'),
(60, 'Ms', 'Katina Korfmann', 'Romance', '0000-00-00', '124288390-8', 'Euro', 4.8, 'Oyope', 'Gaelic', 220, '2025-08-05 10:32:45'),
(61, 'Ms', 'Junia Witty', 'Romance', '0000-00-00', '947418153-5', 'Real', 2.8, 'Viva', 'Dzongkha', 782, '2025-08-05 10:32:45'),
(62, 'Mrs', 'Stephani Camocke', 'Science Fiction', '0000-00-00', '318199371-9', 'Peso', 1.4, 'Dazzlesphere', 'Guarani', 876, '2025-08-05 10:32:45'),
(63, 'Rev', 'Garek Le Floch', 'Thriller', '0000-00-00', '307063071-5', 'Ruble', 2.0, 'Shuffletag', 'Lingala', 3, '2025-08-05 10:32:45'),
(64, 'Dr', 'Rawley Bowshire', 'Fantasy', '0000-00-00', '420448535-9', 'Euro', 2.7, 'Jazzy', 'Kuanyama', 107, '2025-08-05 10:32:45'),
(65, 'Rev', 'Janith Shynn', 'Science Fiction', '0000-00-00', '902107895-3', 'Yuan Renminbi', 3.2, 'Yodel', 'Uzbek', 380, '2025-08-05 10:32:45'),
(66, 'Ms', 'Willamina Bente', 'Science Fiction', '0000-00-00', '726093649-5', 'Rial', 0.8, 'Browsecat', 'Arabic', 530, '2025-08-05 10:32:45'),
(67, 'Dr', 'Vitia Penning', 'Mystery', '0000-00-00', '465233351-X', 'Real', 4.0, 'Ntag', 'Faroese', 95, '2025-08-05 10:32:45'),
(68, 'Ms', 'Arney Addinall', 'Thriller', '0000-00-00', '646185421-5', 'Shilling', 0.1, 'Tanoodle', 'Ukrainian', 397, '2025-08-05 10:32:45'),
(69, 'Mrs', 'Merrel Minghi', 'Romance', '0000-00-00', '874313265-0', 'Peso', 2.6, 'Quimba', 'French', 6, '2025-08-05 10:32:45'),
(70, 'Mrs', 'Christy Blowes', 'Fantasy', '0000-00-00', '618960699-7', 'Yuan Renminbi', 4.3, 'Voolia', 'Assamese', 776, '2025-08-05 10:32:45'),
(71, 'Honorable', 'Sam Lamputt', 'Fantasy', '0000-00-00', '006450582-0', 'Yuan Renminbi', 3.1, 'Layo', 'Divehi', 728, '2025-08-05 10:32:45'),
(72, 'Mr', 'Donielle Worland', 'Fantasy', '0000-00-00', '596803791-1', 'Ruble', 2.9, 'Photobug', 'Catalan', 636, '2025-08-05 10:32:45'),
(73, 'Dr', 'Jimmy Rookeby', 'Thriller', '0000-00-00', '824802881-X', 'Euro', 3.6, 'Wordpedia', 'Kalaallisut', 158, '2025-08-05 10:32:45'),
(74, 'Ms', 'Otha O\'Longain', 'Science Fiction', '0000-00-00', '737767918-2', 'Peso', 0.3, 'Leexo', 'Tagalog', 983, '2025-08-05 10:32:45'),
(75, 'Mr', 'Nico Branson', 'Fantasy', '0000-00-00', '122481896-2', 'Yuan Renminbi', 1.0, 'Twiyo', 'Quechua', 110, '2025-08-05 10:32:45'),
(76, 'Honorable', 'Giacinta Zavattari', 'Fantasy', '0000-00-00', '079456477-1', 'Euro', 3.0, 'Flashspan', 'Latvian', 912, '2025-08-05 10:32:45'),
(77, 'Mrs', 'Gib Simonel', 'Romance', '0000-00-00', '643582551-3', 'Peso', 3.1, 'Realcube', 'Fijian', 376, '2025-08-05 10:32:45'),
(78, 'Ms', 'Leigha Carlos', 'Science Fiction', '0000-00-00', '755318627-9', 'Zloty', 1.2, 'Feedmix', 'Chinese', 805, '2025-08-05 10:32:45'),
(79, 'Rev', 'Fairfax Lehr', 'Science Fiction', '0000-00-00', '820271797-3', 'Yuan Renminbi', 3.5, 'Jamia', 'Abkhazian', 974, '2025-08-05 10:32:45'),
(80, 'Ms', 'Bunny Huckabe', 'Thriller', '0000-00-00', '670116935-X', 'Yuan Renminbi', 2.3, 'Shufflebeat', 'Kannada', 354, '2025-08-05 10:32:45'),
(81, 'Mr', 'Ceciley Iacomi', 'Fantasy', '0000-00-00', '626517527-0', 'Yuan Renminbi', 4.2, 'Tanoodle', 'Hindi', 223, '2025-08-05 10:32:45'),
(82, 'Rev', 'Andrea Otley', 'Science Fiction', '0000-00-00', '484442937-X', 'Yuan Renminbi', 4.1, 'Babbleopia', 'Swahili', 956, '2025-08-05 10:32:45'),
(83, 'Ms', 'Gearalt McKeurton', 'Romance', '0000-00-00', '760505886-1', 'Hryvnia', 0.9, 'Demivee', 'Inupiaq', 497, '2025-08-05 10:32:45'),
(84, 'Rev', 'Ainsley Lethbridge', 'Romance', '0000-00-00', '798995011-1', 'Real', 2.0, 'Skimia', 'Malagasy', 918, '2025-08-05 10:32:45'),
(85, 'Ms', 'Adriena Rapp', 'Mystery', '0000-00-00', '089152383-9', 'Peso', 3.7, 'Skinix', 'Sindhi', 907, '2025-08-05 10:32:45'),
(86, 'Honorable', 'Cherise Damp', 'Romance', '0000-00-00', '468279875-8', 'Hryvnia', 2.8, 'Youfeed', 'Tajik', 166, '2025-08-05 10:32:45'),
(87, 'Dr', 'Coleman Cunniam', 'Mystery', '0000-00-00', '501409422-8', 'Euro', 3.5, 'Pixope', 'Romansh', 314, '2025-08-05 10:32:45'),
(88, 'Ms', 'Shaw Robbie', 'Thriller', '0000-00-00', '061060882-7', 'Hryvnia', 1.7, 'Quinu', 'Indonesian', 847, '2025-08-05 10:32:45'),
(89, 'Rev', 'Bartel Feirn', 'Thriller', '0000-00-00', '168918526-0', 'Ruble', 2.7, 'Twiyo', 'Igbo', 997, '2025-08-05 10:32:45'),
(90, 'Dr', 'Harlie Crook', 'Romance', '0000-00-00', '719576537-7', 'Peso', 3.5, 'Janyx', 'Latin', 825, '2025-08-05 10:32:45'),
(91, 'Honorable', 'Donovan Batecok', 'Thriller', '0000-00-00', '308995437-0', 'Quetzal', 0.5, 'Mita', 'Amharic', 499, '2025-08-05 10:32:45'),
(92, 'Honorable', 'Kristofor Cockshutt', 'Science Fiction', '0000-00-00', '294763923-5', 'Dinar', 0.2, 'Skajo', 'Kuanyama', 184, '2025-08-05 10:32:45'),
(93, 'Ms', 'Yardley Leaming', 'Romance', '0000-00-00', '840308486-2', 'Euro', 2.4, 'Pixope', 'Azerbaijani', 518, '2025-08-05 10:32:45'),
(94, 'Mr', 'Karlens Bygrave', 'Romance', '0000-00-00', '258236080-5', 'Won', 2.4, 'Rhybox', 'Pali', 43, '2025-08-05 10:32:45'),
(95, 'Rev', 'Ambrosius Mithun', 'Romance', '0000-00-00', '931362270-X', 'Peso', 1.0, 'Eazzy', 'Avaric', 975, '2025-08-05 10:32:45'),
(96, 'Honorable', 'Francois Seater', 'Science Fiction', '0000-00-00', '625931450-7', 'Euro', 1.7, 'Yata', 'Amharic', 318, '2025-08-05 10:32:45'),
(97, 'Mr', 'Jodi MacFie', 'Fantasy', '0000-00-00', '688951600-1', 'Peso', 0.5, 'Feedfish', 'Nepali', 338, '2025-08-05 10:32:45'),
(98, 'Dr', 'Vitia Digges', 'Science Fiction', '0000-00-00', '951025484-3', 'Euro', 3.6, 'Yakijo', 'Fulah', 193, '2025-08-05 10:32:45'),
(99, 'Dr', 'Quintin Bainbridge', 'Thriller', '0000-00-00', '813356258-9', 'Rupiah', 2.6, 'Demizz', 'Kanuri', 901, '2025-08-05 10:32:45'),
(100, 'Mrs', 'Erinn Vaudre', 'Science Fiction', '0000-00-00', '219225136-X', 'Rupiah', 3.9, 'Linkbuzz', 'Sundanese', 942, '2025-08-05 10:32:45'),
(101, 'Rev', 'Mirna Vasyutochkin', 'Science Fiction', '0000-00-00', '475005107-1', 'Yuan Renminbi', 0.8, 'Linkbuzz', 'Tswana', 197, '2025-08-05 10:32:45'),
(102, 'Dr', 'Sol Adamou', 'Mystery', '0000-00-00', '909594090-X', 'Rupiah', 0.1, 'Skaboo', 'Sundanese', 381, '2025-08-05 10:32:45'),
(103, 'Ms', 'Myrna Boots', 'Science Fiction', '0000-00-00', '365829924-X', 'Yuan Renminbi', 4.1, 'Oloo', 'Sindhi', 981, '2025-08-05 10:32:45'),
(104, 'Dr', 'Josefa Marcone', 'Romance', '0000-00-00', '198164654-X', 'Yuan Renminbi', 3.6, 'Jaxnation', 'Amharic', 974, '2025-08-05 10:32:45'),
(105, 'Rev', 'Christye Heugle', 'Mystery', '0000-00-00', '418266482-5', 'Rial', 3.1, 'Flipbug', 'Guarani', 738, '2025-08-05 10:32:45'),
(106, 'Dr', 'Kylie Jindrak', 'Romance', '0000-00-00', '354160238-4', 'Dollar', 2.6, 'Babbleblab', 'Gaelic', 696, '2025-08-05 10:32:45'),
(107, 'Honorable', 'Cassaundra Castelot', 'Science Fiction', '0000-00-00', '065534499-3', 'Rupiah', 2.7, 'Pixonyx', 'Kalaallisut', 283, '2025-08-05 10:32:45'),
(108, 'Mr', 'Avram Mowbray', 'Fantasy', '0000-00-00', '989659357-4', 'Rupiah', 4.4, 'Yotz', 'Venda', 807, '2025-08-05 10:32:45'),
(109, 'Dr', 'Joann Moult', 'Thriller', '0000-00-00', '931235704-2', 'Peso', 2.5, 'Cogidoo', 'Kazakh', 958, '2025-08-05 10:32:45'),
(110, 'Mrs', 'Kiri Castard', 'Mystery', '0000-00-00', '256456348-1', 'Yuan Renminbi', 2.1, 'Quaxo', 'Avestan', 52, '2025-08-05 10:32:45'),
(111, 'Dr', 'Durant Mc Meekan', 'Mystery', '0000-00-00', '628568970-9', 'Kyat', 4.0, 'Tazzy', 'Ojibwa', 530, '2025-08-05 10:32:45'),
(112, 'Mr', 'Nanon Lombard', 'Thriller', '0000-00-00', '788602262-9', 'Dollar', 2.1, 'Twitterwire', 'Zulu', 125, '2025-08-05 10:32:45'),
(113, 'Ms', 'Juline Starr', 'Mystery', '0000-00-00', '546732190-0', 'Peso', 4.6, 'Livetube', 'Gujarati', 490, '2025-08-05 10:32:45'),
(114, 'Rev', 'Sherry Crowest', 'Fantasy', '0000-00-00', '929769720-8', 'Yuan Renminbi', 0.6, 'Edgetag', 'Church Slavic', 710, '2025-08-05 10:32:45'),
(115, 'Rev', 'Kermit Kingsley', 'Fantasy', '0000-00-00', '243087862-3', 'Rupiah', 4.3, 'Oyonder', 'Sinhala', 706, '2025-08-05 10:32:45'),
(116, 'Mrs', 'Eadith McVeigh', 'Mystery', '0000-00-00', '806904479-9', 'Yuan Renminbi', 3.0, 'Riffpath', 'Gujarati', 218, '2025-08-05 10:32:45'),
(117, 'Honorable', 'Harp Dowd', 'Romance', '0000-00-00', '158920086-1', 'Lev', 2.3, 'Dabvine', 'Shona', 979, '2025-08-05 10:32:45'),
(118, 'Rev', 'Barnaby Offin', 'Thriller', '0000-00-00', '247235132-1', 'Euro', 2.6, 'Wikido', 'Ganda', 717, '2025-08-05 10:32:45'),
(119, 'Mr', 'Arne Grundwater', 'Fantasy', '0000-00-00', '371690162-8', 'Litas', 2.1, 'Topiclounge', 'Turkmen', 781, '2025-08-05 10:32:45'),
(120, 'Honorable', 'Lorilee Schwier', 'Science Fiction', '0000-00-00', '342967342-9', 'Yuan Renminbi', 2.1, 'Jaxworks', 'Dutch', 104, '2025-08-05 10:32:45'),
(121, 'Mr', 'Toddy McNeigh', 'Thriller', '0000-00-00', '412291720-4', 'Euro', 4.0, 'Abatz', 'German', 943, '2025-08-05 10:32:45'),
(122, 'Dr', 'Peterus Sabathe', 'Thriller', '0000-00-00', '257373032-8', 'Baht', 0.6, 'Oba', 'Marshallese', 746, '2025-08-05 10:32:45'),
(123, 'Rev', 'Gwendolen Fidler', 'Mystery', '0000-00-00', '118101831-5', 'Ruble', 0.4, 'Jamia', 'Nepali', 184, '2025-08-05 10:32:45'),
(124, 'Ms', 'Kin McWhin', 'Thriller', '0000-00-00', '924018524-0', 'Yen', 0.6, 'Oyondu', 'Estonian', 598, '2025-08-05 10:32:45'),
(125, 'Dr', 'Ramon Enderson', 'Thriller', '0000-00-00', '307510128-1', 'Euro', 4.4, 'Meevee', 'Chuvash', 51, '2025-08-05 10:32:45'),
(126, 'Rev', 'Kelcy Glassborow', 'Mystery', '0000-00-00', '659301396-X', 'Yuan Renminbi', 1.9, 'Teklist', 'Norwegian', 55, '2025-08-05 10:32:45'),
(127, 'Mr', 'Jeremiah Giller', 'Mystery', '0000-00-00', '439699853-8', 'Krona', 0.1, 'Gigazoom', 'Urdu', 34, '2025-08-05 10:32:45'),
(128, 'Mrs', 'Merl Paolillo', 'Science Fiction', '0000-00-00', '297207210-3', 'Yuan Renminbi', 4.2, 'Quire', 'Lithuanian', 414, '2025-08-05 10:32:45'),
(129, 'Ms', 'Timmie Thurlbourne', 'Thriller', '0000-00-00', '965096971-3', 'Rupiah', 2.3, 'Gigazoom', 'Inuktitut', 269, '2025-08-05 10:32:45'),
(130, 'Rev', 'Theodosia Chatres', 'Thriller', '0000-00-00', '740871505-3', 'Euro', 3.5, 'Livetube', 'Slovak', 894, '2025-08-05 10:32:45'),
(131, 'Ms', 'Lanette Pichan', 'Thriller', '0000-00-00', '689163029-0', 'Shilling', 1.1, 'Einti', 'Chamorro', 851, '2025-08-05 10:32:45'),
(132, 'Mr', 'Loydie Havock', 'Romance', '0000-00-00', '131110820-3', 'Cordoba', 3.8, 'Agivu', 'Volapük', 26, '2025-08-05 10:32:45'),
(133, 'Ms', 'Laure Stansbury', 'Mystery', '0000-00-00', '787061666-4', 'Yuan Renminbi', 1.4, 'Tavu', 'Marshallese', 687, '2025-08-05 10:32:45'),
(134, 'Mrs', 'Zilvia Lowe', 'Science Fiction', '0000-00-00', '820366470-9', 'Hryvnia', 1.2, 'Flashdog', 'Tswana', 966, '2025-08-05 10:32:45'),
(135, 'Rev', 'Cheryl Izakovitz', 'Science Fiction', '0000-00-00', '812598887-4', 'Peso', 4.1, 'Dynava', 'Nepali', 70, '2025-08-05 10:32:45'),
(136, 'Mr', 'Katerine Measey', 'Romance', '0000-00-00', '838849471-6', 'Peso', 0.8, 'Leenti', 'Guarani', 665, '2025-08-05 10:32:45'),
(137, 'Honorable', 'Bryant Briant', 'Mystery', '0000-00-00', '428426645-4', 'Euro', 5.0, 'Blogtag', 'Oromo', 628, '2025-08-05 10:32:45'),
(138, 'Honorable', 'Horacio Delaprelle', 'Thriller', '0000-00-00', '998000276-X', 'Euro', 4.5, 'Quimba', 'Albanian', 556, '2025-08-05 10:32:45'),
(139, 'Mr', 'Marshall Cressy', 'Thriller', '0000-00-00', '147238468-7', 'Rupiah', 0.7, 'Kwimbee', 'Twi', 775, '2025-08-05 10:32:45'),
(140, 'Mr', 'Euphemia Huckell', 'Fantasy', '0000-00-00', '080897492-0', 'Dong', 0.2, 'Meevee', 'Hungarian', 459, '2025-08-05 10:32:45'),
(141, 'Honorable', 'Lauralee Shiels', 'Thriller', '0000-00-00', '182829975-8', 'Rupiah', 0.2, 'Trudoo', 'Oriya', 444, '2025-08-05 10:32:45'),
(142, 'Dr', 'Crissy Ladbury', 'Fantasy', '0000-00-00', '597795435-2', 'Yuan Renminbi', 3.8, 'Gabvine', 'Maori', 553, '2025-08-05 10:32:45'),
(143, 'Honorable', 'Thaxter Kitman', 'Mystery', '0000-00-00', '410089707-3', 'Yuan Renminbi', 4.0, 'Jaxbean', 'Interlingua (International Auxiliary Language Asso', 890, '2025-08-05 10:32:45'),
(144, 'Rev', 'Mariam Trundler', 'Fantasy', '0000-00-00', '756433242-5', 'Rupiah', 1.7, 'Babblestorm', 'Kirghiz', 516, '2025-08-05 10:32:45'),
(145, 'Mr', 'Brunhilde Keyes', 'Mystery', '0000-00-00', '119926491-1', 'Peso', 5.0, 'Dynava', 'Wolof', 537, '2025-08-05 10:32:45'),
(146, 'Mr', 'Alexandros Piggins', 'Mystery', '0000-00-00', '999785812-3', 'Ruble', 1.0, 'Thoughtstorm', 'Bambara', 520, '2025-08-05 10:32:45'),
(147, 'Rev', 'Roi Stoven', 'Romance', '0000-00-00', '120930124-5', 'Rupiah', 0.5, 'Yakijo', 'Ganda', 172, '2025-08-05 10:32:45'),
(148, 'Rev', 'Shalom Sadgrove', 'Science Fiction', '0000-00-00', '538799937-4', 'Yen', 4.8, 'Oyope', 'Sinhala', 970, '2025-08-05 10:32:45'),
(149, 'Mr', 'Cob Chmiel', 'Thriller', '0000-00-00', '241435683-9', 'Ouguiya', 0.8, 'Einti', 'Slovenian', 317, '2025-08-05 10:32:45'),
(150, 'Mrs', 'Gregg Spellecy', 'Fantasy', '0000-00-00', '585220555-9', 'Krona', 1.1, 'Abatz', 'Sichuan Yi', 449, '2025-08-05 10:32:45'),
(151, 'Ms', 'Gates Gounod', 'Fantasy', '0000-00-00', '380489768-1', 'Euro', 3.0, 'Zoomcast', 'Church Slavic', 685, '2025-08-05 10:32:45'),
(152, 'Mr', 'Terrill Ritchard', 'Fantasy', '0000-00-00', '107312945-4', 'Rupiah', 4.0, 'Twimm', 'Armenian', 963, '2025-08-05 10:32:45'),
(153, 'Dr', 'Upton Ettles', 'Fantasy', '0000-00-00', '096950068-8', 'Dollar', 1.9, 'Eazzy', 'Basque', 399, '2025-08-05 10:32:45'),
(154, 'Rev', 'Peterus Escudier', 'Romance', '0000-00-00', '831685753-7', 'Afghani', 3.7, 'Flipopia', 'Russian', 533, '2025-08-05 10:32:45'),
(155, 'Mr', 'Grove Dudden', 'Fantasy', '0000-00-00', '707508538-7', 'Yuan Renminbi', 1.6, 'Dynava', 'Somali', 771, '2025-08-05 10:32:45'),
(156, 'Dr', 'Eydie Quirk', 'Mystery', '0000-00-00', '072439073-1', 'Yuan Renminbi', 1.1, 'Skynoodle', 'Latin', 982, '2025-08-05 10:32:45'),
(157, 'Mr', 'Rhonda Rue', 'Mystery', '0000-00-00', '018869335-1', 'Peso', 0.8, 'Voonte', 'Ndonga', 660, '2025-08-05 10:32:45'),
(158, 'Mrs', 'Davidson Colomb', 'Science Fiction', '0000-00-00', '100628475-3', 'Yuan Renminbi', 0.1, 'Flashset', 'Mongolian', 18, '2025-08-05 10:32:45'),
(159, 'Mrs', 'Wittie Cromblehome', 'Thriller', '0000-00-00', '808809774-6', 'Rupee', 3.9, 'Ailane', 'Afrikaans', 838, '2025-08-05 10:32:45'),
(160, 'Honorable', 'Palmer Dougan', 'Fantasy', '0000-00-00', '227853321-5', 'Rupiah', 2.5, 'Skimia', 'Wolof', 414, '2025-08-05 10:32:45'),
(161, 'Honorable', 'Charlot Abramowitch', 'Romance', '0000-00-00', '017126343-X', 'Yen', 4.6, 'Browsetype', 'Welsh', 944, '2025-08-05 10:32:45'),
(162, 'Ms', 'Annnora Labbati', 'Fantasy', '0000-00-00', '219203831-3', 'Yuan Renminbi', 1.0, 'Wikizz', 'Irish', 14, '2025-08-05 10:32:45'),
(163, 'Mr', 'Cathyleen Yakobowitch', 'Thriller', '0000-00-00', '537592527-3', 'Baht', 1.9, 'Vimbo', 'Avaric', 687, '2025-08-05 10:32:45'),
(164, 'Dr', 'Thekla Primett', 'Fantasy', '0000-00-00', '296009945-1', 'Zloty', 4.0, 'Kwilith', 'Sango', 382, '2025-08-05 10:32:45'),
(165, 'Mr', 'Robert Kingzeth', 'Romance', '0000-00-00', '510899847-3', 'Rial', 0.6, 'Oozz', 'English', 808, '2025-08-05 10:32:45'),
(166, 'Ms', 'Fulton Jepps', 'Mystery', '0000-00-00', '965009273-0', 'Rupiah', 0.5, 'Feednation', 'Akan', 392, '2025-08-05 10:32:45'),
(167, 'Mr', 'Sybille De Meyer', 'Romance', '0000-00-00', '412403360-5', 'Euro', 0.1, 'Quaxo', 'Faroese', 599, '2025-08-05 10:32:45'),
(168, 'Rev', 'Ennis Letty', 'Mystery', '0000-00-00', '350665427-6', 'Yuan Renminbi', 0.3, 'Jazzy', 'Nepali', 523, '2025-08-05 10:32:45'),
(169, 'Rev', 'Derk Canland', 'Romance', '0000-00-00', '917464192-1', 'Rupiah', 0.5, 'Ooba', 'Zhuang', 702, '2025-08-05 10:32:45'),
(170, 'Mr', 'Charo Stubbert', 'Romance', '0000-00-00', '044599288-3', 'Yuan Renminbi', 3.7, 'Blogpad', 'Oromo', 725, '2025-08-05 10:32:45'),
(171, 'Mr', 'Seth Spoor', 'Fantasy', '0000-00-00', '548851259-4', 'Dollar', 4.2, 'Gigazoom', 'Oromo', 553, '2025-08-05 10:32:45'),
(172, 'Rev', 'Roana Wilsey', 'Fantasy', '0000-00-00', '119360381-1', 'Yuan Renminbi', 3.6, 'Meetz', 'Sango', 72, '2025-08-05 10:32:45'),
(173, 'Ms', 'Tyson Solomonides', 'Romance', '0000-00-00', '798346979-9', 'Peso', 3.3, 'Jayo', 'Luba-Katanga', 869, '2025-08-05 10:32:45'),
(174, 'Dr', 'Valaree Paolillo', 'Mystery', '0000-00-00', '063136916-3', 'Real', 3.4, 'Browsebug', 'Croatian', 817, '2025-08-05 10:32:45'),
(175, 'Honorable', 'Artie Snedden', 'Science Fiction', '0000-00-00', '717893313-5', 'Yuan Renminbi', 1.3, 'Skidoo', 'French', 185, '2025-08-05 10:32:45'),
(176, 'Ms', 'Allyce Waddup', 'Science Fiction', '0000-00-00', '476466272-8', 'Peso', 4.7, 'Jabberbean', 'Norwegian', 961, '2025-08-05 10:32:45'),
(177, 'Rev', 'Kalil Hawkins', 'Science Fiction', '0000-00-00', '036903952-1', 'Yuan Renminbi', 3.7, 'Katz', 'Aymara', 359, '2025-08-05 10:32:45'),
(178, 'Ms', 'Darsey Slite', 'Science Fiction', '0000-00-00', '971955714-1', 'Yuan Renminbi', 1.6, 'Zoomzone', 'Assamese', 416, '2025-08-05 10:32:45'),
(179, 'Honorable', 'Latia Handscomb', 'Romance', '0000-00-00', '275168983-3', 'Peso', 2.5, 'Miboo', 'Telugu', 23, '2025-08-05 10:32:45'),
(180, 'Honorable', 'Laurene Booth', 'Science Fiction', '0000-00-00', '295159710-X', 'Krona', 2.9, 'Yoveo', 'Shona', 582, '2025-08-05 10:32:45'),
(181, 'Rev', 'Arvin Hause', 'Romance', '0000-00-00', '087509313-2', 'Euro', 0.3, 'Eazzy', 'Chuvash', 431, '2025-08-05 10:32:45'),
(182, 'Dr', 'Mada Wicks', 'Fantasy', '0000-00-00', '696835877-8', 'Rupiah', 2.4, 'Aimbu', 'Shona', 670, '2025-08-05 10:32:45'),
(183, 'Mr', 'Mona Crosher', 'Thriller', '0000-00-00', '759177925-7', 'Rupiah', 3.6, 'Eamia', 'Armenian', 888, '2025-08-05 10:32:45'),
(184, 'Mrs', 'Broderick Hillin', 'Thriller', '0000-00-00', '619534288-2', 'Ruble', 0.1, 'Rhybox', 'Indonesian', 929, '2025-08-05 10:32:45'),
(185, 'Ms', 'Ailina Culvey', 'Thriller', '0000-00-00', '742679874-7', 'Koruna', 2.2, 'Abatz', 'Tagalog', 799, '2025-08-05 10:32:45'),
(186, 'Honorable', 'Cherrita Etock', 'Fantasy', '0000-00-00', '371486469-5', 'Euro', 1.4, 'Yozio', 'Irish', 936, '2025-08-05 10:32:45'),
(187, 'Honorable', 'Ethyl Winfred', 'Science Fiction', '0000-00-00', '632310310-9', 'Yuan Renminbi', 4.8, 'Zoonoodle', 'Sichuan Yi', 343, '2025-08-05 10:32:45'),
(188, 'Rev', 'Gerladina Slarke', 'Fantasy', '0000-00-00', '635967027-5', 'Euro', 0.8, 'Yambee', 'Telugu', 463, '2025-08-05 10:32:45'),
(189, 'Ms', 'Merci Haller', 'Science Fiction', '0000-00-00', '654532843-3', 'Real', 1.5, 'Youopia', 'Luxembourgish', 176, '2025-08-05 10:32:45'),
(190, 'Mrs', 'Marline Barbour', 'Science Fiction', '0000-00-00', '149238095-4', 'Ruble', 1.5, 'Youfeed', 'Inuktitut', 40, '2025-08-05 10:32:45'),
(191, 'Mr', 'Adan Thickens', 'Science Fiction', '0000-00-00', '261349542-1', 'Bolivar', 2.4, 'Topicblab', 'Sango', 960, '2025-08-05 10:32:45'),
(192, 'Mr', 'Shawn Itzchaki', 'Fantasy', '0000-00-00', '842829014-8', 'Krona', 4.3, 'Tagtune', 'Tamil', 702, '2025-08-05 10:32:45'),
(193, 'Honorable', 'Dorolisa Spendley', 'Fantasy', '0000-00-00', '120288641-8', 'Lev', 4.3, 'Skivee', 'Navajo', 937, '2025-08-05 10:32:45'),
(194, 'Mrs', 'Ettie Bittlestone', 'Thriller', '0000-00-00', '646989800-9', 'Euro', 3.1, 'Browsetype', 'Corsican', 73, '2025-08-05 10:32:45'),
(195, 'Honorable', 'Garrek Aberkirdo', 'Romance', '0000-00-00', '450675896-X', 'Rupiah', 1.5, 'Babbleopia', 'Greek, Modern (1453-)', 609, '2025-08-05 10:32:45'),
(196, 'Honorable', 'Lisette Mora', 'Mystery', '0000-00-00', '011146114-6', 'Franc', 3.3, 'Fanoodle', 'Gujarati', 880, '2025-08-05 10:32:45'),
(197, 'Honorable', 'Peta Willmot', 'Romance', '0000-00-00', '698898431-3', 'Yen', 1.0, 'Topicblab', 'German', 934, '2025-08-05 10:32:45'),
(198, 'Rev', 'Russell Hovenden', 'Mystery', '0000-00-00', '908724798-2', 'Rupee', 4.8, 'Nlounge', 'Czech', 315, '2025-08-05 10:32:45'),
(199, 'Rev', 'Terry Allnutt', 'Mystery', '0000-00-00', '342202505-7', 'Ruble', 1.9, 'Dynabox', 'Guarani', 432, '2025-08-05 10:32:45'),
(200, 'Honorable', 'Issiah Ackery', 'Science Fiction', '0000-00-00', '669822455-3', 'Hryvnia', 0.1, 'Shuffletag', 'Nepali', 370, '2025-08-05 10:32:45'),
(201, 'Mr', 'Aggie Woodcraft', 'Science Fiction', '0000-00-00', '733505897-X', 'Peso', 4.6, 'Feedspan', 'Western Frisian', 726, '2025-08-05 10:32:45'),
(202, 'Ms', 'Cos Alyukin', 'Mystery', '0000-00-00', '857189018-8', 'Euro', 1.5, 'Blogtags', 'Kikuyu', 431, '2025-08-05 10:32:45');

--
-- Índices para tabelas despejadas
--

--
-- Índices de tabela `book_store`
--
ALTER TABLE `book_store`
  ADD PRIMARY KEY (`book_id`);

--
-- AUTO_INCREMENT para tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `book_store`
--
ALTER TABLE `book_store`
  MODIFY `book_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=203;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
