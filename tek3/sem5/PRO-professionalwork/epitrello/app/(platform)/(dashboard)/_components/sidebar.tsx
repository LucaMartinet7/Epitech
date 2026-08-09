"use client";

import Link from "next/link";
import { Plus } from "lucide-react";
import { useLocalStorage } from "usehooks-ts";
import { useOrganizationList, useOrganization } from "@clerk/nextjs";

import { Button } from "@/components/ui/button";
import { Separator } from "@/components/ui/separator";
import { Skeleton } from "@/components/ui/skeleton";
import { Accordion } from "@/components/ui/accordion";
import { NavItem, Organization } from "./nav-item";

// Define the props for the Sidebar component
interface SidebarProps {
    storageKey?: string; // Optional storage key for local storage
}

export const Sidebar = ({
    storageKey = "t-sidebar-state", // Default storage key maybe need one for mobile
}: SidebarProps) => {
    // State for expanded accordion items, stored in local storage
    // use local storage to persist the expanded state across sessions
    const [expanded, setExpanded] = useLocalStorage<Record<string, any>>(storageKey, {});

    // Get the active organization and loading state
    // need to know the active organization to highlight it in the UI
    const {
        organization: activeOrganization,
        isLoaded: isLoadedOrg
    } = useOrganization();

    // Get the list of user memberships and loading state
    // Fetching the list of organizations the user is a member of allows us to display them in the sidebar
    const {
        userMemberships,
        isLoaded: isLoadedOrgList
    } = useOrganizationList({
        userMemberships: {
            infinite: true, // Enable infinite loading
            // Infinite loading ensures that all user memberships are fetched, even if there are many
        }
    });

    // Calculate the default expanded accordion items based on local storage state
    // This ensures that the accordion items that were expanded in the previous session remain expanded
    const defaultAccordionValue: string[] = Object.keys(expanded).reduce((acc: string[], key: string) => {
        if (expanded[key]) {
            acc.push(key);
        }
        return acc;
    }, []);

    // Handle expanding/collapsing accordion items
    // updates the local storage
    const onExpand = (id: string) => {
        setExpanded({
            ...expanded,
            [id]: !expanded[id] // Toggle the expanded state
        });
    };

    // Show loading state if data is not loaded yet
    if (!isLoadedOrg || !isLoadedOrgList || userMemberships.isLoading) {
        return (
            <>
            <div className="flex items-center justify-between mb-2">
                <Skeleton className="h-10 w-[50%]"/> {/* Skeleton loader */}
                <Skeleton className="h-10 w-10" />
            </div>
            <div className="space-y-2">
                <NavItem.Skeleton />
                <NavItem.Skeleton />
                <NavItem.Skeleton />
            </div>
            </>
        );
    }

    return (
        <>
            <div className="font-medium text-xs flex items-center mb-1">
                <span className="pl-4">
                    Workspaces
                </span>
                <Button asChild type="button" size="icon" variant="ghost" className="ml-auto">
                    <Link href="/select-org">
                        <Plus className="h-4 w-4" />
                    </Link>
                </Button>
            </div>
            <Accordion type="multiple" defaultValue={defaultAccordionValue} className="space-y-2">
                {userMemberships.data.map(({ organization }) => (
                    <NavItem
                        key={organization.id} // Unique key for each NavItem
                        isActive={activeOrganization?.id === organization.id} // Check if the organization is active
                        isExpanded={expanded[organization.id]} // Check if the organization is expanded
                        organization={organization as Organization} // Pass organization data
                        onExpand={onExpand} // Handle expand/collapse
                    />
                ))}
            </Accordion>
        </>
    );
};