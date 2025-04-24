package com.OptixCXM.AYS;

import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.KeyEvent;
import java.util.regex.*;

import org.openqa.selenium.By;
import org.openqa.selenium.JavascriptExecutor;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.logging.LogEntries;
import org.openqa.selenium.logging.LogEntry;
import org.openqa.selenium.logging.LogType;
import org.testng.annotations.Test;

import com.e2e.Utilities.BaseClass;
import com.e2e.Utilities.CommonFunctions;
import com.e2e.Utilities.WebDriverInstance;
import com.e2e.Utilities.WebDriverUtility;

public class VBuild_Login extends BaseClass {

	private static WebDriverInstance wdinstance;
	
	// Property file path
	public static String ApplPropFilePath = "PropertyFiles/CXM.properties";
	
	// Property values
	public static String url = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "CXM_URL");
	public static String username = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "CXM_UserName");
	public static String password = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "CXM_Password");
	public static String ssoUsername = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "sso_username");
	public static String ssoPassword = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "sso_pass");
	public static String ssoSignIn = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "sso_signIn");
	public static String Iagree = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "agree");

	public static String SecondToggle = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "SecondToggle");
	public static String SearchEWO = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "SearchEWO");
	public static String TechWorkCenter = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "TechWorkCenter");
	public static String Baltimore = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "Baltimore");
	public static String searchbtn = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "searchbtn");
	public static String SearchTech = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "SearchTech");
	public static String MoreOptions = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "MoreOptions");
	public static String Cxm_LogOut = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "Cxm_LogOut");

	public static String CWA_clear = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "CWA_clear");
	public static String CWA_Date = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "CWA_Date");
	public static String CWA_DateToday = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "CWA_DateToday");
	public static String CWA_Region = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "CWA_Region");
	public static String CWA_RegionCP = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "CWA_RegionCP");
	public static String EWO_L1 = CommonFunctions.getPropValuesFromFile(ApplPropFilePath, "EWO_L1");

	@Test
	public static void CXMLogin() {
		try {
			wdinstance = new WebDriverInstance();
			driver = wdinstance.getWebDriverInstace("Chrome");

			driver.get(url);
			JavascriptExecutor js = (JavascriptExecutor) driver;
			js.executeScript("document.body.style.zoom='100%'");

			// Login process
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(ssoUsername), 30).sendKeys(username);
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(ssoPassword), 30).sendKeys(password);
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(ssoSignIn), 30).click();
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(Iagree), 30).click();

			System.out.println("********CXM logged in Successfully*********");
		} catch (Exception e) {
			System.out.println(e.toString());
		}
	}

	@Test
	public static void Construction_WorkAssignment() throws InterruptedException {
		try {
			Thread.sleep(4000);
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(SecondToggle), 30).click();
			Thread.sleep(2000);
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(CWA_clear), 30).click();
			Thread.sleep(2000);
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(CWA_Date), 30).click();
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(CWA_DateToday), 30).click();
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(CWA_Region), 30).click();
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(CWA_RegionCP), 30).click();
			Thread.sleep(2000);
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(searchbtn), 30).click();

			Thread.sleep(3000);
			WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(EWO_L1), 30).click();
			Thread.sleep(3000);

			// Press ENTER to trigger browser action (if needed)
			try {
				Robot robot = new Robot();
				robot.keyPress(KeyEvent.VK_ENTER);
				robot.keyRelease(KeyEvent.VK_ENTER);
			} catch (AWTException e) {
				e.printStackTrace();
			}

			Thread.sleep(2000);

			// Extract Microsoft Edge URL from browser log
			LogEntries logEntries = driver.manage().logs().get(LogType.BROWSER);

			for (LogEntry entry : logEntries) {
				String msg = entry.getMessage();
				Pattern pattern = Pattern.compile("Not allowed to launch 'microsoft-edge:(.*?)'");
				Matcher matcher = pattern.matcher(msg);

				if (matcher.find()) {
					String edgeUrl = matcher.group(1);
					System.out.println("Extracted Edge URL: " + edgeUrl);

					// Launch Edge with the extracted URL
					driver.quit();
					driver = wdinstance.getWebDriverInstace("Edge");
					driver.get(edgeUrl);

					WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(ssoUsername), 30).sendKeys(username);
					WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(ssoPassword), 30).sendKeys(password);
					WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(ssoSignIn), 30).click();
					WebDriverUtility.waitForVisibilityOfElementLocated(driver, wait, By.xpath(Iagree), 30).click();
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}