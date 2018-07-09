/*
 Navicat Premium Data Transfer

 Source Server         : cys
 Source Server Type    : MySQL
 Source Server Version : 50719
 Source Host           : localhost:3306
 Source Schema         : market

 Target Server Type    : MySQL
 Target Server Version : 50719
 File Encoding         : 65001

 Date: 03/07/2018 12:05:37
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for admin
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin`  (
  `AID` int(20) NOT NULL,
  `Aname` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `Apassword` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`AID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES (111, 'admin', '111');

-- ----------------------------
-- Table structure for class
-- ----------------------------
DROP TABLE IF EXISTS `class`;
CREATE TABLE `class`  (
  `CLID` int(11) NOT NULL,
  `CLname` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`CLID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of class
-- ----------------------------
INSERT INTO `class` VALUES (0, '书籍');
INSERT INTO `class` VALUES (1, '家具');
INSERT INTO `class` VALUES (2, '服饰');
INSERT INTO `class` VALUES (3, '零食');
INSERT INTO `class` VALUES (4, '化妆品');
INSERT INTO `class` VALUES (5, '电子设备');
INSERT INTO `class` VALUES (6, '其他');

-- ----------------------------
-- Table structure for condition
-- ----------------------------
DROP TABLE IF EXISTS `condition`;
CREATE TABLE `condition`  (
  `CID` int(11) NOT NULL,
  `Cname` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`CID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of condition
-- ----------------------------
INSERT INTO `condition` VALUES (5, '五成新');
INSERT INTO `condition` VALUES (6, '六成新');
INSERT INTO `condition` VALUES (7, '七成新');
INSERT INTO `condition` VALUES (8, '八成新');
INSERT INTO `condition` VALUES (9, '九成新');
INSERT INTO `condition` VALUES (10, '全新');

-- ----------------------------
-- Table structure for message
-- ----------------------------
DROP TABLE IF EXISTS `message`;
CREATE TABLE `message`  (
  `SID` int(20) NOT NULL,
  `PID` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Mess` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`SID`, `PID`) USING BTREE,
  INDEX `PID2`(`PID`) USING BTREE,
  CONSTRAINT `PID2` FOREIGN KEY (`PID`) REFERENCES `product` (`PID`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `SID12` FOREIGN KEY (`SID`) REFERENCES `student` (`SID`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of message
-- ----------------------------
INSERT INTO `message` VALUES (1, '{0a18b235-5769-4cb6-bad9-ee3a39d1e5d6}', '啥颜色的呀');
INSERT INTO `message` VALUES (1, '{32166223-9bac-46dd-a2d3-2235a05c2be9}', '芒果味的有吗');
INSERT INTO `message` VALUES (730, '{0a18b235-5769-4cb6-bad9-ee3a39d1e5d6}', '贵了，便宜点吧');
INSERT INTO `message` VALUES (918, '{151b3e11-39f2-41a7-92d8-f84d99b85086}', '111');
INSERT INTO `message` VALUES (918, '{5532a2b4-c8d8-4231-b6b2-6754ba05e720}', '111');
INSERT INTO `message` VALUES (918, '{712b7bdf-0023-44b5-a4a8-4c584911b9d6}', '11');
INSERT INTO `message` VALUES (918, '{80357af4-bedf-4e17-883a-defa17b5fc3b}', '好用');

-- ----------------------------
-- Table structure for product
-- ----------------------------
DROP TABLE IF EXISTS `product`;
CREATE TABLE `product`  (
  `PID` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Pname` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `Pprice` float(100, 0) NULL DEFAULT NULL,
  `Pdescription` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `CLID` int(11) NULL DEFAULT NULL,
  `CID` int(11) NULL DEFAULT NULL,
  `SID` int(30) NULL DEFAULT NULL,
  PRIMARY KEY (`PID`) USING BTREE,
  INDEX `CID1`(`CID`) USING BTREE,
  INDEX `CLID1`(`CLID`) USING BTREE,
  INDEX `SID123`(`SID`) USING BTREE,
  CONSTRAINT `CID1` FOREIGN KEY (`CID`) REFERENCES `condition` (`CID`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `CLID1` FOREIGN KEY (`CLID`) REFERENCES `class` (`CLID`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `SID123` FOREIGN KEY (`SID`) REFERENCES `student` (`SID`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of product
-- ----------------------------
INSERT INTO `product` VALUES ('{03dc0109-a3e9-42ec-a006-6d2e0f7549ee}', '网吧二手机', 500, '性价比极高', 5, 5, 302);
INSERT INTO `product` VALUES ('{06b56897-5307-4454-ba68-456f95831d45}', '解忧杂货店', 20, '无敌了', 0, 8, 918);
INSERT INTO `product` VALUES ('{0a18b235-5769-4cb6-bad9-ee3a39d1e5d6}', 'mac口红', 100, '用了一点点，然后就一直没用了', 4, 8, 730);
INSERT INTO `product` VALUES ('{151b3e11-39f2-41a7-92d8-f84d99b85086}', '人性的弱点', 99, '\n好看', 0, 10, 918);
INSERT INTO `product` VALUES ('{2d6516da-8b28-410e-ad49-32416cd86e1e}', '咪咪虾条', 0, '吃多了上火', 3, 10, 302);
INSERT INTO `product` VALUES ('{32166223-9bac-46dd-a2d3-2235a05c2be9}', '冰淇淋', 10, '好吃好吃，多种可供参考', 3, 10, 730);
INSERT INTO `product` VALUES ('{4340b959-e07a-429a-aa3d-aad05bed828e}', '嫌疑人X的献身', 5, '超好看', 0, 5, 918);
INSERT INTO `product` VALUES ('{5532a2b4-c8d8-4231-b6b2-6754ba05e720}', 'sk2', 300, '神仙水对皮肤很好专治痘痘肌', 4, 8, 302);
INSERT INTO `product` VALUES ('{5a9b9a6e-3282-48b7-9cbe-48d27b70b96e}', '手表', 20, '快了', 5, 8, 918);
INSERT INTO `product` VALUES ('{5fd40d76-7d1a-41a5-9bfd-009d2005afcd}', 'jason\'s pc', 666, '(♥∀♥)', 5, 8, 918);
INSERT INTO `product` VALUES ('{712b7bdf-0023-44b5-a4a8-4c584911b9d6}', '小木椅子', 15, '原价是30元，然后一直没用过', 1, 10, 730);
INSERT INTO `product` VALUES ('{80357af4-bedf-4e17-883a-defa17b5fc3b}', '白t', 30, '衣服太多处理一些', 2, 10, 730);
INSERT INTO `product` VALUES ('{82177594-10db-4eeb-95d2-e4ada6c5229c}', '大板凳', 11, '很好用', 1, 10, 302);
INSERT INTO `product` VALUES ('{92deae3d-e0a4-4bf5-87f7-67d7b4e20425}', '麦田守望者', 20, '\n学委推荐', 0, 10, 1);
INSERT INTO `product` VALUES ('{d58ce489-8951-4792-9642-acfd4a62a512}', '计算机组成原理', 10, '用不上了\n', 0, 8, 730);
INSERT INTO `product` VALUES ('{e4ae6248-c6b3-4cc9-924d-51c43ee63451}', '大佬的袜子', 100, '超有味道', 2, 5, 918);
INSERT INTO `product` VALUES ('{e64f0918-b6c9-4267-8217-64813e727681}', '空气刘海假发', 100, '很好看', 2, 6, 302);
INSERT INTO `product` VALUES ('{e99e4c2d-451b-4a15-92d8-ecd12c94063b}', '花瓶', 1, '玻璃花瓶，闲置处理', 6, 9, 730);
INSERT INTO `product` VALUES ('{ebe75f62-6fe7-4e90-877e-9bf8c42aa984}', '安卓数据线', 1, '多余的', 5, 9, 730);

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student`  (
  `SID` int(20) NOT NULL,
  `Sname` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Scontact` varchar(30) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `Spassword` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Ssex` varchar(19) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`SID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES (1, '吴', '1', '1', '女孩子');
INSERT INTO `student` VALUES (161, '161', '161', '161', '男孩子');
INSERT INTO `student` VALUES (302, '卢', '111', '302', '男孩子');
INSERT INTO `student` VALUES (305, '刘', '111', '305', '男孩子');
INSERT INTO `student` VALUES (730, '陈', '13627142332', '730', '女孩子');
INSERT INTO `student` VALUES (918, '918', '123', '918', '男孩子');

-- ----------------------------
-- Table structure for trade_record
-- ----------------------------
DROP TABLE IF EXISTS `trade_record`;
CREATE TABLE `trade_record`  (
  `TID` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `SID1` int(20) NOT NULL,
  `SID2` int(20) NOT NULL,
  `PID` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`TID`) USING BTREE,
  INDEX `SID1`(`SID1`) USING BTREE,
  INDEX `SID2`(`SID2`) USING BTREE,
  INDEX `PID3`(`PID`) USING BTREE,
  CONSTRAINT `PID3` FOREIGN KEY (`PID`) REFERENCES `product` (`PID`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `SID1` FOREIGN KEY (`SID1`) REFERENCES `student` (`SID`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `SID2` FOREIGN KEY (`SID2`) REFERENCES `student` (`SID`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of trade_record
-- ----------------------------
INSERT INTO `trade_record` VALUES ('{28175f38-d35b-4f74-abe6-8d2d6d0aa96e}', 1, 302, '{03dc0109-a3e9-42ec-a006-6d2e0f7549ee}');
INSERT INTO `trade_record` VALUES ('{3a89de3b-1fbb-4dd0-9e57-f69b53f13c6d}', 730, 302, '{2d6516da-8b28-410e-ad49-32416cd86e1e}');
INSERT INTO `trade_record` VALUES ('{4ba5bca5-17e5-4dbf-bf93-7d2633ba6cc4}', 1, 302, '{e64f0918-b6c9-4267-8217-64813e727681}');
INSERT INTO `trade_record` VALUES ('{7e7be535-04f3-4adb-b2a2-df317df8edd1}', 918, 1, '{92deae3d-e0a4-4bf5-87f7-67d7b4e20425}');

SET FOREIGN_KEY_CHECKS = 1;
