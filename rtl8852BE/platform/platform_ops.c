/******************************************************************************
 *
 * Copyright(c) 2013 - 2022 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/
#include <linux/pci.h>
#include <linux/printk.h>
#include <drv_types.h>
#include "platform_ops.h"

static void platform_wifi_remove_endpoint(void)
{
	struct pci_dev *pdev;

	/* Keep the root bridge's BAR and MSI configuration intact. */
	pdev = pci_get_device(PCI_VENDOR_ID_REALTEK, 0xb852, NULL);
	if (!pdev)
		return;

	pci_stop_and_remove_bus_device_locked(pdev);
	pci_dev_put(pdev);
}

/*
* Return:
* 0 on success, negative error code on failure
*/
int platform_wifi_power_on(void)
{
	pr_info("%s: PCIe wifi power on\n", __func__);
	platform_wifi_remove_endpoint();
	set_usb_wifi_power(0);
	set_usb_wifi_power(1);
	pci_reinit();

	return 0;
}

void platform_wifi_power_off(void)
{
	pr_info("%s: PCIe wifi power down\n", __func__);
	platform_wifi_remove_endpoint();
	set_usb_wifi_power(0);
}

void platform_wifi_get_oob_irq(int *oob_irq)
{

}

void platform_wifi_mac_addr(u8 *mac_addr)
{

}
